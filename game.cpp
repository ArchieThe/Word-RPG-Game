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
Game::Game() {
    std::string player_name;
    std::cout << "Enter your player's name: ";
    std::getline(std::cin, player_name);
    player_.setName(player_name);
    std::cout << "Welcome, " << player_.getName() << "!\n";

    // Attempt to load existing game
    if (loadGame("savefile.txt", player_)) {
        std::cout << "Game loaded successfully.\n";
    } else {
        std::cout << "Starting a new game.\n";
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

