#ifndef AREAS_H
#define AREAS_H
#include <iostream>

class Area {
protected:
    std::string name;
    std::string description;

public:
    virtual ~Area() = default;
    virtual bool enter() = 0; // enter
    virtual bool exit() = 0;// exit

    // Getters
    std::string getName() const;
    std::string getDescription() const;

    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
};


#endif