#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

#include "slime.h"

//constructor
Slime::Slime(int health, int damage) {
    this->name = "Slime";
    this->baseHealth = 5;
    this->baseDamage = 1;
    this->health_ = health;
    this->damage_ = damage;
    this->totalHealth_ = health_+baseHealth;
}
Slime::Slime():Slime(5,1){}


//getters
int Slime::get_health() const {
    return health_;
}
int Slime::get_damage() const {
    return damage_;
}
int Slime::get_totalHealth() const {
    return totalHealth_;
}


//setters
void Slime::set_health(int health) {
    this->health_ = health;
}   
void Slime::set_damage(int damage) {
    this->damage_ = damage;
}
void Slime::set_totalHealth(int totalHealth) {
    this->totalHealth_ = totalHealth;
}


//other methods

//attack method where slime attacks player and player attacks slime
Player* Slime::attack(Player* player) {
    int player_hp = player->getHp();
    int player_dmg = player->getAtk();
    int slime_hp = this->get_totalHealth();

    //slime attacks player
    player_hp -= damage_+baseDamage;
    player->setHp(player_hp);

    //player attacks slime
    slime_hp -= player_dmg;
    this->set_totalHealth(slime_hp);
    return player;
}


//fight method where slime and player fight until one is dead
Player* Slime::fight(Player* player)
{
    if (!player)
        return nullptr;

    std::cout << "⚔️  Battle Start: " << player->getName()
              << " vs " << this->get_name() << "!\n\n\n";

    int round = 1;

    //Loop until either the player or the slime is dead
    while (player->getHp() > 0 && this->get_totalHealth() > 0)
    {
        std::cout << "----- Round " << round << " -----\n";

        //Slime attacks (this also reduces slime’s HP when player counter-attacks)
        this->attack(player);

        std::cout << player->getName() << "'s HP: " << player->getHp() << "\n";
        std::cout << this->get_name() << "'s HP: " << this->get_totalHealth() << "\n\n\n";

        //short pause for readability
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