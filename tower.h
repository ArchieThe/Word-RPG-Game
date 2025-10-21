#include "iostream"
#include "areas.h"

class tower : public Area{
public:
    tower();
    bool enter();
    bool exit();
};