#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <string>
#include <algorithm>

#include "player.h"

class Monster
{
protected:
    int baseHealth;
    std::string name;
    int baseDamage; 

public:

//getters
    int get_baseHealth()const;
    int get_baseDamage() const;
    std::string get_name() const;

//setters
    void set_baseHealth(int baseHealth);
    void set_baseDamage(int baseDamage);
    void set_name(const std::string& name);

//other methods
    virtual Player* attack(Player* playerName)=0;
    virtual Player* fight(Player* playerName)=0; 
};




#endif 