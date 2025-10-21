#include "player.h" 
#include <utility>

// Default constructor
Player::Player():Player("Default"){};

// Parameterized constructor
Player::Player(std::string name): 
    name_(std::move(name)),
    hp_(20),
    max_hp_(20),
    atk_(4),
    def_(2),
    gold_(0){}

//getters
std::string Player::getName() {return name_;}
int Player::getHp() {return hp_;}
int Player::getMaxHp() {return max_hp_;}
int Player::getAtk() {return atk_;}
int Player::getDef() {return def_;}
int Player::getGold() {return gold_;}

//setters 
void Player::setName(const std::string& name) {name_ = name;}
void Player::setHp(int hp) {hp_ = std::clamp(hp, 0, max_hp_);}
void Player::setMaxHp(int max_hp) {max_hp_ = max_hp;}
void Player::setAtk(int atk) {atk_ = atk;}
void Player::setDef(int def) {def_ = def;}
void Player::setGold(int gold) {gold_ = gold;}    