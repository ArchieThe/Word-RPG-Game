#ifndef VARIANT_H
#define VARIANT_H
#include "slime.h"

#include <iostream>
#include <string>


class Variant : public Slime{
protected:
    int extraHealth_;
    int extraDamage_;
    int def_;

public:

//constructor
    Variant();
    Variant(int extraHealth, int extraDamage, int def);


//getters
int get_extraHealth() const;
int get_extraDamage() const;
int get_def() const;


//setters
void set_extraHealth(int extraHealth);
void set_extraDamage(int extraDamage);
void set_def(int def);

//other methods
Player* attack(Player* Player) override;
Player* fight(Player* playerName) override;
};



#endif