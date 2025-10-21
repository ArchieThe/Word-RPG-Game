#include <iostream>
#include <string>
#include <algorithm>

#include "monster.h"
#include "player.h"


//getters
int Monster::get_baseHealth() const {
    return baseHealth;
}
int Monster::get_baseDamage() const {
    return baseDamage;
}   
std::string Monster::get_name() const {
    return name;
}   


//setters
void Monster::set_baseHealth(int health) {
    this->baseDamage = health;
}
void Monster::set_baseDamage(int damage) {
    this->baseDamage = damage;
}
void Monster::set_name(const std::string& name) {
    this->name = name;
}
