#pragma once
#include "Location.h"

class Animal {
public:
    virtual void printDetails() = 0;
    virtual char getInitial() = 0;
    const Location getLocation() const; // get the location of the animal
    virtual void step() = 0;
    void stop();
    virtual ~Animal() {} // virtual destructor
    void move(); // move the animal
    virtual void turnVertically() {}; // turn the animal vertically
    virtual void turnHorizontally() {}; // turn the animal horizontally



protected:
    Animal(const std::string& name, const Location& location); // constructor
    std::string name;
    Location location;
    bool canMove;

    int rows = 20; // number of rows in the zoo
    int cols = 40; // number of columns in the zoo

    // helper function to check if location is within bounds of zoo
    bool is_within_bounds(Location loc);


};

