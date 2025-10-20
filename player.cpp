#include "player.h"
#include "monster.h"

player::player(){
    name = "guest";
    health = 100;
    damage = 10 ;
    gold = 0;

}
player::player(std::string name){
    this->name = name;
}

player* player::attack(player* playerName){
    if (playerName->get_health() > 0){
        take_damage(damage);
        
    }
    return playerName;


}

monster* player::attack(monster* target){
    if (target->get_health()>0){
        target->take_damage(damage);
    }
    return target;
    
}



void player::use_item(/*Items* itemName*/){
    //Items.apply(); 




}

int player::get_health()const{
    return health;

 }
int player::get_damage() const{
    return damage;

}
std::string player::get_name() const{
    return name;

}

int player::get_gold() const{
    return gold;
}




void player::display_status(){
    std:: cout<< "Name: "<< name<<std::endl;
    std:: cout<< "Health: "<< health<<std::endl;
    std:: cout<< "Damage: "<< damage<<std::endl;
    std:: cout<< "Gold: "<<gold<<std::endl;



}

void player:: take_damage(int amount){
    this->health-= amount;
    if (health<=0){
        health = 0;
    }
    

    return;
    
}