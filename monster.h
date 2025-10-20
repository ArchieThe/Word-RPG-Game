#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>

class player;

class monster
{
protected:
    int health ;
    std::string name;
    int damage; 

public:
   
    virtual player* attack(player* playerName);
    monster();
    int get_health()const;
    int get_damage() const;
    std::string get_name() const;

    
    void take_damage(int amount);
};







#endif 