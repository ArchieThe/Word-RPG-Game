#include "plains.h"
#include <iostream>

Plains::Plains(){
    name = "Open Plains";
    description = "A vast expanse of open land with tall grasses swaying in the breeze.";
};

bool Plains::enter(){
    std::cout << "You step into the " << name << ". " << description << std::endl;
    return true;
};

bool Plains::exit(){
    std::cout << "You leave the " << name << "." << std::endl;
    return false;
}


