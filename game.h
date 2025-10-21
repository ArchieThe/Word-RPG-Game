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
private:
    Player player_;

public:
    Game();  // constructor to set up the player
    void start(); // main game loop
    void showMenu(); // display menu options
    void fightSlime(); // handle slime battle
    void goToTower(); // placeholder for future content
};

#endif