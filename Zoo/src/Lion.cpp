#include "Lion.h"
#include "Lion.h"
#include "Lion.h"

Lion::Lion(const std::string& name, const Location& location) : Animal(name, location)
{
}

void Lion::printDetails()
{
    std::cout << "Lion - " << name << " Location:"<< location << std::endl;
}

char Lion::getInitial()
{
    return 'L';
}

void Lion::step()
{
    if (canMove)
    {
        location += Location(0, 2 * direction);

        if (!is_within_bounds(location))
        {
            location += Location(0, -2 * direction);
            turnHorizontally();

        }
    }
}

Lion::~Lion()
{

}

void Lion::turnHorizontally()
{
    direction *= -1;
}
