#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class monster;

class player
{
protected:
    int health;
    int gold ;
    std::string name;
    int damage;
    


public:
    player();
    player(std::string name);
    player* attack(player* playerName);
    void use_item();
    void display_status();
    monster* attack(monster* target);
    void take_damage(int amount);
    int get_health()const;
    int get_damage() const;
    std::string get_name() const;
    int get_gold() const;

  
    

};










#endif