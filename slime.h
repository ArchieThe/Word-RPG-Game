#ifndef SLIME_H
#define SLIME_H
#include <iostream>
#include <string>
#include <algorithm>

#include "monster.h"
#include "player.h"

class Slime: public Monster {
protected:
    int damage_;
    int health_;
    int totalHealth_;

public:
//constructor
    Slime();
    Slime(int health, int damage);


//getters
    int get_health() const;
    int get_damage() const;
    int get_totalHealth() const;


//setters
    void set_health(int health);
    void set_damage(int damage);
    void set_totalHealth(int totalHealth);


//other methods
    Player* attack(Player* Player) override;
    Player* fight(Player* playerName) override;

    
};
#endif