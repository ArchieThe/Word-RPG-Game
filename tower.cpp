#include <iostream>
#include "tower.h"

Tower::Tower(){
    name = "Ancient Tower";
    description = "A tall, crumbling tower that reaches into the sky, filled with ancient secrets.";
};
bool Tower::enter(){
    std::cout << "You enter the " << name << ". " << description << std::endl;
    return true;
}
bool Tower::exit(){
    std::cout << "You leave the " << name << "." << std::endl;
    return false;
}