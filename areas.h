#ifndef AREAS_H
#define AREAS_H
#include <iostream>

class Area {
protected:
    std::string name;
    std::string description;

public:
    virtual bool enter() = 0; // Pure virtual function
    virtual bool exit() = 0;// Default implementation

    // Getters
    std::string getName() const;
    std::string getDescription() const;

    // Setters
    void setName(const std::string& name) {
        this->name = name;
    }
    void setDescription(const std::string& description) {
        this->description = description;
    }
};


#endif