#include <iostream>
#include "areas.h"

//getters
std::string Area::getName() const{
    return name;
}
std::string Area::getDescription() const{
    return description;
}
void Area::setName(const std::string& name){
        this->name = name;
}
void Area::setDescription(const std::string& description){
        this->description = description;
}