#ifndef TOWER_H
#define TOWER_H
#include "iostream"
#include "areas.h"

class Tower : public Area{
public:
    Tower();
    bool enter() override;
    bool exit() override;
};

#endif