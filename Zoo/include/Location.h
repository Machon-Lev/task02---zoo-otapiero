#pragma once
#include <iostream>

struct Location {
    int x;
    int y;

    Location(int x = 0, int y = 0); // constructor

    Location operator+=(const Location& rhs);
    Location operator-=(const Location& rhs);

    bool operator==(const Location& rhs) const; // check if two locations are equal
    bool operator!=(const Location& rhs) const; // check if two locations are not equal

    friend std::ostream& operator<<(std::ostream& os, const Location& loc); // print a location
};


