#ifndef PLAINS_H
#define PLAINS_H

#include "iostream"
#include "areas.h"

class Plains : public Area{
public:
    Plains();
    bool enter();
    bool exit();
};

#endif