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
    gold_(0),
    exp_(0){}

//getters
std::string Player::getName() const {return name_;}
int Player::getHp() const {return hp_;}
int Player::getMaxHp() const {return max_hp_;}
int Player::getAtk() const {return atk_;}
int Player::getDef() const {return def_;}
int Player::getGold() const {return gold_;}
int Player::getExp() const {return exp_;}
void Player::getStats() const {
    std::cout << "Player Stats:\n";
    std::cout << "Name: " << name_ << "\n";
    std::cout << "HP: " << hp_ << "/" << max_hp_ << "\n";
    std::cout << "ATK: " << atk_ << "\n";
    std::cout << "DEF: " << def_ << "\n";
    std::cout << "Gold: " << gold_ << "\n";
    std::cout << "EXP: " << exp_ << "\n";
}

//setters 
void Player::setName(const std::string& name) {name_ = name;}
void Player::setHp(int hp) {hp_ = std::clamp(hp, 0, max_hp_);}
void Player::setMaxHp(int max_hp) {max_hp_ = max_hp;}
void Player::setAtk(int atk) {atk_ = atk;}
void Player::setDef(int def) {def_ = def;}
void Player::setGold(int gold) {gold_ = gold;}    
void Player::setExp(int exp) {exp_ = exp;}