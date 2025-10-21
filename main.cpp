#include "game.h"
#include <iostream>

int main() {
    std::cout << "===== Welcome to the Adventure RPG =====\n\n";

    Game game;    //Constructor will load or create player data
    game.run();   //Start the main game loop

    std::cout << "\n===== Exiting Game =====\n";
    return 0;
}
