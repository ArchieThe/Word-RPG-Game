#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Player; 

class Item {
private:
    std::string name;       
    int price;             
    int extraDamage;        
    int extraArmor;         

public:
    Item(std::string name = "Unknown Item", int price = 0, int dmg = 0, int armor = 0);

    std::string getName() const;
    int getPrice() const;
    int getExtraDamage() const;
    int getExtraArmor() const;

    void setName(const std::string& newName);
    void setPrice(int newPrice);
    void setExtraDamage(int newDamage);
    void setExtraArmor(int newArmor);

    void apply(Player& target);

    void display() const;
};

#endif
