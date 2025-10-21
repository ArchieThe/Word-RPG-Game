#ifndef TOWER_H
#define TOWER_H
#include "iostream"
#include "areas.h"

class tower : public Area{
public:
    tower();
    bool enter();
    bool exit();
};

#endif