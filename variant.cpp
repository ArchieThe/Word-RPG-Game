#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

#include "variant.h"


//constructor
Variant::Variant(int extraHealth, int extraDamage, int def){
    this->name = "Variant";
    this->baseHealth = 5;
    this->baseDamage = 1;
    this->extraHealth_ = extraHealth;
    this->extraDamage_ = extraDamage;
    this->def_ = def;
    this->health_ = 6;
    this->damage_ = 2;
    this->totalHealth_ = health_ + baseHealth + extraHealth_;
}
Variant::Variant():Variant(5,2,1){}



//getters
int Variant::get_extraHealth() const {
    return extraHealth_;
}
int Variant::get_extraDamage() const {
    return extraDamage_;
}
int Variant::get_def() const {
    return def_;
}



//setters
void Variant::set_extraHealth(int extraHealth) {
    this->extraHealth_ = extraHealth;  
}
void Variant::set_extraDamage(int extraDamage) {
    this->extraDamage_ = extraDamage;
}
void Variant::set_def(int def) {
    this->def_ = def;
}   



//other methods


//attack method where da variant attacks player and player attacks variant
Player* Variant::attack(Player* player) {
    int player_hp = player->getHp();
    int player_dmg = player->getAtk();
    int Variant_hp = this->get_totalHealth();

    //variant attacks player
    player_hp -= damage_+baseDamage+extraDamage_;
    player->setHp(player_hp);

    //variant attacks slime
    Variant_hp -= (player_dmg-def_);
    this->set_totalHealth(Variant_hp);
    return player;
}



//fight method where variant and player fight until one is dead
Player* Variant::fight(Player* player){
    {
    if (!player)
        return nullptr;

    std::cout << "⚔️  Battle Start: " << player->getName()
              << " vs " << this->get_name() << "!\n\n\n";

    int round = 1;

    // Loop until either the player or the slime is dead
    while (player->getHp() > 0 && this->get_totalHealth() > 0)
    {
        std::cout << "----- Round " << round << " -----\n";

        //Variant attacks (this also reduces Variant HP when player counter-attacks)
        this->attack(player);

        std::cout << player->getName() << "'s HP: " << player->getHp() << "\n";
        std::cout << this->get_name() << "'s HP: " << this->get_totalHealth() << "\n\n\n";

        // Optional short pause for readability
        std::this_thread::sleep_for(std::chrono::milliseconds(4000));

        ++round;
    }

    // Determine the outcome
    if (player->getHp() <= 0 && this->get_totalHealth() <= 0)
        std::cout << "It's a draw! Both " << player->getName()
                  << " and " << this->get_name() << " have fallen!\n";
    else if (player->getHp() <= 0)
        std::cout << player->getName() << " was defeated by the "
                  << this->get_name() << "!\n";
    else
        std::cout << player->getName() << " defeated the "
                  << this->get_name() << "!\n";

    return player;
}
}