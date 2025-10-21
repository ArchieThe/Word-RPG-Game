#include "item.h"
#include "player.h"

using namespace std;

Item::Item(string name, int price, int dmg, int armor)
    : name(name), price(price), extraDamage(dmg), extraArmor(armor) {}

string Item::getName() const { return name; }
int Item::getPrice() const { return price; }
int Item::getExtraDamage() const { return extraDamage; }
int Item::getExtraArmor() const { return extraArmor; }

void Item::setName(const string& newName) { name = newName; }
void Item::setPrice(int newPrice) { price = newPrice; }
void Item::setExtraDamage(int newDamage) { extraDamage = newDamage; }
void Item::setExtraArmor(int newArmor) { extraArmor = newArmor; }

void Item::apply(Player& target) {
    cout << "Applying " << name << " to player..." << endl;
    if (extraDamage > 0)
        cout << "Damage increased by " << extraDamage << " points.\n";
    if (extraArmor > 0)
        cout << "Armor increased by " << extraArmor << " points.\n";
}

void Item::display() const {
    cout << "Item: " << name
         << " | Price: " << price
         << " | +Damage: " << extraDamage
         << " | +Armor: " << extraArmor
         << endl;
}
