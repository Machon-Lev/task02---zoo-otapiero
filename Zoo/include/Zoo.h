#pragma once

#include <vector>
#include "Animal.h"
#include "Location.h"
#include "Lion.h"
#include "Shark.h"
#include "ClownFish.h"
#include <string>

class Zoo {
public:
    Zoo(); // constructor
    ~Zoo(); // destructor


    void run(); // run the zoo simulation

private:

    std::vector<Animal*> animal_map; // vector of pointers to animals



    void stop(const int animal_number); // stop one animal from moving
    void move(const int animal_number); // make an animal move
    void create(const std::string &animal_type,const std::string &name); // create a new animal
    void del(const int number); // delete one animal
    void delAll(const std::string& animal_type); // delete all animals of a certain type
    void help()const; // print help text explaining available functions and parameters
    void step(); // make the next move for all animals

    void printMap()const; // print the map of the zoo
    void printList()const; // print the list of animals
    static bool is_srand_initiallized;

    Location getRandomLocation(); // get a random location within the bounds of the zoo
};