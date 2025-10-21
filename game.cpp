#include "game.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Constructor to set up the player
Game::Game(){
    std::string player_name;
    std::cout << "Enter your player's name: ";
    std::getline(std::cin, player_name);
    player_= Player(player_name);

    // Attempt to load existing game
    loadGame("savefile.txt", player_);

    std::cout << "Game loaded successfully.\n";
    std::cout << "Welcome, " << player_.getName() << "!\n";
    std::cout << "Starting location: Plains\n\n";
    location_ = Location::Plains;
}

Game::~Game(){
    std::cout << "Game Over. Thanks for playing!\n";
    appendOrUpdatePlayer(savePath_, player_);
}




//main game loop
void Game::run() {
    bool running = true;

    while (running) {
        switch (location_) {
        case Location::Plains:
            showPlainsMenu();
            break;
        case Location::Tower:
            showTowerMenu();
            break;
        }

        int choice = readMenuChoice(1, 4);

        if (location_ == Location::Plains) {
            handlePlainsChoice(choice, running);
        } else {
            handleTowerChoice(choice, running);
        }

        if (running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
            std::cout << "\n";
        }
    }
}




//menus for da areas
void Game::showPlainsMenu() const {
    std::cout << "\n === Plains ===\n"
              << "1) Check stats\n"
              << "2) Fight slime\n"
              << "3) Go to tower\n"
              << "4) Quit\n"
              << "Choose: ";
}

void Game::showTowerMenu() const {
    std::cout << "\n=== Tower ===\n"
              << "1) Check stats\n"
              << "2) Fight variant\n"
              << "3) Go to plains\n"
              << "4) Quit\n"
              << "Choose: ";
}





//handle choices in areas save me
void Game::handlePlainsChoice(int choice, bool& running) {
    switch (choice) {
    case 1: showStats(); break;
    case 2: fightSlime(); break;
    case 3:
        location_ = Location::Tower;
        std::cout << "You travel to the Tower...\n";
        break;
    case 4:
        appendOrUpdatePlayer(savePath_, player_);
        running = false;
        break;
    default: break;
    }
}

void Game::handleTowerChoice(int choice, bool& running) {
    switch (choice) {
    case 1: showStats(); break;
    case 2: fightVariant(); break;
    case 3:
        location_ = Location::Plains;
        std::cout << "You descend to the Plains...\n";
        break;
    case 4:
        appendOrUpdatePlayer(savePath_, player_);
        running = false;
        break;
    default: break;
    }
}








//Actionsssssssss
void Game::showStats() const {
    std::cout << "\n-- " << player_.getName() << " --\n"
              << "HP:   " << player_.getHp() << "/" << player_.getMaxHp() << "\n"
              << "ATK:  " << player_.getAtk() << "\n"
              << "DEF:  " << player_.getDef() << "\n"
              << "GOLD: " << player_.getGold() << "\n\n";
}

void Game::fightSlime() {
    // Create a fresh slime for each battle
    Slime slime;

    // Ensure slime has full health at battle start if it’s stateful across uses
    slime.set_totalHealth(8);

    // Run battle
    slime.fight(&player_);

    // After battle outcome
    if (player_.getHp() <= 0) {
        std::cout << "You collapse on the plains...\n";
        std::cout << "Game Over. Thanks for playing!\n";
        // (Optionally end run, reload, or set HP to 1)
        return;
    } else if (slime.get_totalHealth() <= 0) {
        //reward for killing slime
        int gold = 2;
        player_.setGold(player_.getGold() + gold);
        std::cout << "You loot " << gold << " gold from the slime.\n";
    }
}

void Game::fightVariant() {
    Variant variant; // likewise, pass any needed constructor args

    // variant.set_totalHealth(variant_base_hp); // if needed

    variant.fight(&player_);

    if (player_.getHp() <= 0) {
        //endgame
        std::cout << "You fall within the tower’s. No-one will remember you name.\n";
        appendOrUpdatePlayer(savePath_, player_);
        return;

    } else if (variant.get_totalHealth() <= 0) {
        //reward for killing variant
        int gold = 5;
        player_.setGold(player_.getGold() + gold);
        std::cout << "You claim " << gold << " gold from the variant.\n";
    }
}







//input helper
int Game::readMenuChoice(int minOpt, int maxOpt) const {
    int choice = 0;
    while (true) {
        if (std::cin >> choice && choice >= minOpt && choice <= maxOpt) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number between "
                  << minOpt << " and " << maxOpt << ": ";
    }
}








//load save file
// returns true if it parsed a matching line and loaded into player
bool Game::parseAndLoadLine(const std::string& line, const std::string& wantedName, Player& player) {
    // Split into "name" and "stats"
    auto commaPos = line.find(',');
    if (commaPos == std::string::npos) return false;

    std::string name = line.substr(0, commaPos);
    std::string stats = line.substr(commaPos + 1);

    if (name != wantedName) return false;

    // stats is "hp:max:atk:def:gold"
    std::istringstream iss(stats);
    std::string hpStr, maxStr, atkStr, defStr, goldStr;

    if (!std::getline(iss, hpStr, ':'))  return false;
    if (!std::getline(iss, maxStr, ':')) return false;
    if (!std::getline(iss, atkStr, ':')) return false;
    if (!std::getline(iss, defStr, ':')) return false;
    if (!std::getline(iss, goldStr))     return false;

    try {
        int hp   = std::stoi(hpStr);
        int max  = std::stoi(maxStr);
        int atk  = std::stoi(atkStr);
        int def  = std::stoi(defStr);
        int gold = std::stoi(goldStr);

        // Load into player
        player.setMaxHp(max);      // set max first so clamping of HP works
        player.setHp(hp);
        player.setAtk(atk);
        player.setDef(def);
        player.setGold(gold);
        return true;
    } catch (...) {
        return false; // malformed numbers
    }
}



// Create the file and write the current player as the first entry
bool Game::createSaveFileWithPlayer(const std::string& filename, const Player& player){
    std::ofstream out(filename);
    if (!out) return false;
    out << player.getName() << ","
        << player.getHp()   << ":"
        << player.getMaxHp()<< ":"
        << player.getAtk()  << ":"
        << player.getDef()  << ":"
        << player.getGold() << "\n";
    return true;
}



// Overwrite or append helpers (optional)
bool Game::appendOrUpdatePlayer(const std::string& filename, const Player& player){
    //read all, replace line for this name if found and if not append
    std::ifstream in(filename);
    std::vector<std::string> lines;
    bool replaced = false;

    if (in){
        std::string line;
        while (std::getline(in, line)){
            auto commaPos = line.find(',');
            if (commaPos != std::string::npos && line.substr(0, commaPos) == player.getName()){
                std::ostringstream oss;
                oss << player.getName() << ","
                    << player.getHp()   << ":"
                    << player.getMaxHp()<< ":"
                    << player.getAtk()  << ":"
                    << player.getDef()  << ":"
                    << player.getGold();
                lines.push_back(oss.str());
                replaced = true;
            } else {
                lines.push_back(line);
            }
        }
    }
    in.close();

    if (!replaced) {
        std::ostringstream oss;
        oss << player.getName() << ","
            << player.getHp()   << ":"
            << player.getMaxHp()<< ":"
            << player.getAtk()  << ":"
            << player.getDef()  << ":"
            << player.getGold();
        lines.push_back(oss.str());
    }

    std::ofstream out(filename, std::ios::trunc);
    if (!out) return false;
    for (const auto& l : lines) out << l << "\n";
    return true;
}



//creates file if missing; if exists and loads stats for matching name
bool Game::loadGame(const std::string& filename, Player& player){
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Save file not found. Creating new one...\n";
        if (!createSaveFileWithPlayer(filename, player)) {
            std::cout << "Error: could not create " << filename << "\n";
            return false;
        }
        std::cout << "New save file created successfully.\n";
        return true;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (parseAndLoadLine(line, player.getName(), player)) {
            std::cout << "Loaded save for " << player.getName() << "\n";
            return true;
        }
    }



    //Append this new player with default stats if cannot find.
    file.close();
    if (appendOrUpdatePlayer(filename, player)){
        std::cout << "No existing save for " << player.getName()
                  << ". Added a new entry.\n";
        return true;
    } else {
        std::cerr << "Error: could not update " << filename << "\n";
        return false;
    }
}

