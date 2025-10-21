#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

#include "player.h"
#include "monster.h"
#include "slime.h"
#include "variant.h"
#include "areas.h"
#include "plains.h"
#include "tower.h"

int main() {

    std::cout << "Test driver for word RPG:\n";


//testing player class
    Player Player("Archie");
    assert(Player.getName() == "Archie");

    Player.setAtk(5);
    assert(Player.getAtk() == 5);

    Player.setHp(15);
    assert(Player.getHp() == 15);

    Player.setDef(5);
    assert(Player.getDef() == 5);

    Player.setGold(100);
    assert(Player.getGold() == 100);

    Player.setMaxHp(50);
    assert(Player.getMaxHp() == 50);


//testing slime class
    Slime slime1(6,2);
    assert(slime1.get_name() == "Slime");
    assert(slime1.get_health() == 6);
    assert(slime1.get_damage() == 2);
    assert(slime1.get_baseHealth() == 5);
    assert(slime1.get_baseDamage() == 1);
    assert(slime1.get_totalHealth() == 11); //6+5

//slime attacks player and player attacks slime
    slime1.attack(&Player);
    assert(Player.getHp() == 12); //15-(2+1) = 12
    assert(slime1.get_totalHealth() == 6); //11 - 5 = 6 


//we make them fight bro 
    slime1.fight(&Player); //fight until one is defeated
    assert(Player.getHp() > 0); //player should win
    assert(slime1.get_totalHealth() <= 0); //slime should be defeated


//variant attacks player and player attacks variant
    Player.setHp(20); //reset player hp
    Variant variant1;
    
    assert(variant1.get_totalHealth() == 16); //6+5+5
    variant1.attack(&Player);
    assert(Player.getHp() == 15); //20-(2+1+2) = 15
    assert(variant1.get_totalHealth() == 12); //16 - (5-1) = 10


//variant and player fight
    variant1.fight(&Player); //fight until one is defeated
    assert(Player.getHp() == 0); //draw
    assert(variant1.get_totalHealth() == 0); //variant should be defeated
    


//test areas
    Plains plainsArea;
    assert(plainsArea.getName() == "Open Plains");
    assert(plainsArea.getDescription() == "A vast expanse of open land with tall grasses swaying in the breeze.");
    assert (plainsArea.enter() == true);
    assert (plainsArea.exit() == false);

    tower towerArea;
    assert(towerArea.getName() == "Ancient Tower");
    assert(towerArea.getDescription() == "A tall, crumbling tower that reaches into the sky, filled with ancient secrets.");
    assert (towerArea.enter() == true);
    assert (towerArea.exit() == false);

    std::cout << "All tests passed!\n";

    return 0;
}