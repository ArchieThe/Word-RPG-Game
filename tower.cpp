#include <iostream>
#include "tower.h"

Tower::Tower(){
    name = "Ancient Tower";
    description = "The air is heavy and dust fills your lungs as you step inside the tower.";
}
bool Tower::enter(){
    std::cout << "You enter the " << name << ". " << description << std::endl;
    return true;
}
bool Tower::exit(){
    std::cout << "You leave the " << name << "." << std::endl;
    return false;
}