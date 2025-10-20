#ifndef SLIME_H
#define SLIME_H
#include <iostream>
#include "monster.h"
#include "player.h"

class slime : public monster
{
private:

    int slime_level ;



public:
    slime();
   
    player* attack(player* playerName) override;
};




#endif 