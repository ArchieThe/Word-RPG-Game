#include "monster.h"
#include "player.h"

monster :: monster(){
    health = 100;
    name = "monster";
    damage = 20; 

}


player* monster::attack(player* playerName) {
    if (playerName->get_health() > 0){
        playerName->take_damage(damage);
        
    }
    return playerName;

   
}

void monster:: take_damage(int amount){
    this->health-= amount;
    if (health<=0){
        health = 0;
    }
    


    return;
    
}

int monster::get_damage()const{
    return damage;
}

int monster::get_health() const{
    return health;

}

std::string monster::get_name() const{
    return name;

}