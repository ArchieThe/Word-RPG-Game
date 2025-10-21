#include "game.h"
#include <iostream>
#include <limits>
#include <thread>
#include <chrono>


// Constructor to set up the player
Game::Game() {
    std::string player_name;
    std::cout << "Enter your player's name: ";
    std::getline(std::cin, player_name);
    player_.setName(player_name);
    std::cout << "Welcome, " << player_.getName() << "!\n";
}


