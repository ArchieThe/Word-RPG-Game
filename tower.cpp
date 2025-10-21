#include <iostream>
#include "tower.h"

tower::tower(){
    name = "Ancient Tower";
    description = "A tall, crumbling tower that reaches into the sky, filled with ancient secrets.";
};
bool tower::enter(){
    std::cout << "You enter the " << name << ". " << description << std::endl;
    return true;
}
bool tower::exit(){
    std::cout << "You leave the " << name << "." << std::endl;
    return false;
}