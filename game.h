#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "slime.h"
#include "tower.h"
#include "areas.h"
#include "plains.h"
#include "variant.h"


#include <iostream>
#include <string>

class Game {
protected:
    Player player_;

public:
//get player
    Player& getPlayer() {return player_;}
//mian game 
    Game();  // constructor to set up the player
    void start(); // main game loop
//fight stuff
    void fightSlime(); // handle slime battle
    void fightVariant(); // handle tower guard battle
//exploration stuff
    void explorePlains(int choice); // handle plains exploration
    void exploreTower(int choice); // handle tower exploration

//reader and safeFile writer.
    bool saveGame(const std::string& filename, Player& player); // save game state to file
    bool loadGame(const std::string& filename, Player& player); // load game state from file
    static bool parseAndLoadLine(const std::string& line, const std::string& wantedName, Player& player);
    static bool createSaveFileWithPlayer(const std::string& filename, const Player& player);
    static bool appendOrUpdatePlayer(const std::string& filename, const Player& player);

};

#endif