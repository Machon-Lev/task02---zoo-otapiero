#include "Location.h"

Location::Location(int x, int y) : x(x), y(y) {}

Location Location::operator+=(const Location& rhs) 
{

    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}


bool Location::operator==(const Location& rhs) const 
{
    return x == rhs.x && y == rhs.y;
}

bool Location::operator!=(const Location& rhs) const 
{
    return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const Location& loc) 
{
    os << "(" << loc.x << ", " << loc.y << ")";
    return os;
}
Location Location::operator-=(const Location& rhs) 
{
    this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}
