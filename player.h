#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <algorithm>


class Player {
protected:
    std::string name_;
    int hp_{20};
    int max_hp_{20};
    int atk_{4};
    int def_{2};
    int gold_{0};
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
// setters
    void setName(const std::string& name);
    void setHp(int hp);
    void setMaxHp(int max_hp);
    void setAtk(int atk);
    void setDef(int def);
    void setGold(int gold);

};

#endif

