#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <algorithm>


class Player {
protected:
    std::string name_;
    int hp_;
    int max_hp_;
    int atk_;
    int def_;
    int gold_;
    int exp_;
public:
// constructors
    Player();
    Player(std::string name);
// getters
    std::string getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getAtk() const;
    int getDef() const;
    int getGold() const;
    void getStats() const;
    int getExp() const;
// setters
    void setName(const std::string& name);
    void setHp(int hp);
    void setMaxHp(int max_hp);
    void setAtk(int atk);
    void setDef(int def);
    void setGold(int gold);
    void setExp(int exp);

};

#endif

