#include "slime.h"
#include "player.h"

slime::slime() : monster(), slime_level(){
    slime_level = 1 ; 
    damage = 10; 
}

player* slime::attack(player* playerName)  {
    if (playerName->get_health() > 0){
        playerName->take_damage(damage);
        
    }
    return playerName;


};