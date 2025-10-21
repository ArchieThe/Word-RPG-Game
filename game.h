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

enum class Location { Plains, Tower };

class Game {
protected:
    Player player_;
    Area* currentArea_ = nullptr;  
    Location location_ = Location::Plains;
    const std::string savePath_ = "savefile.txt";
    Plains plainsArea_;
    Tower towerArea_;

public:
//get player
    Player& getPlayer() {return player_;}
//mian game 
    Game();  //constructor to set up the player
    ~Game();
    void run(); //main game loop
    
//actions I guess
    void fightSlime(); //handle slime battle
    void fightVariant(); //handle tower var battle
    void showStats() const;

//exploration stuff 
    void showPlainsMenu() const;
    void handlePlainsChoice(int choice, bool& running); //explore the plains area
    void showTowerMenu() const;
    void handleTowerChoice(int choice, bool& running); //explore the tower area

//input helppppp
    int readMenuChoice(int minOpt, int maxOpt) const;

//reader and safeFile writer.
    bool loadGame(const std::string& filename, Player& player); //load game state from file
    static bool parseAndLoadLine(const std::string& line, const std::string& wantedName, Player& player);
    static bool createSaveFileWithPlayer(const std::string& filename, const Player& player);
    static bool appendOrUpdatePlayer(const std::string& filename, const Player& player);

};

#endif