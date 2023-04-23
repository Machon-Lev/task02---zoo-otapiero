#include "Animal.h"

const Location Animal::getLocation() const
{
	return Location(location.x, location.y);
}

void Animal::stop()
{
	canMove = false;
}

void Animal::move()
{
	canMove = true;
}

Animal::Animal(const std::string& name, const Location& location) :name(name), location(location)
{
	canMove = true;
}
bool Animal::is_within_bounds(Location loc)
{
	return loc.x >= 0 && loc.x < rows && loc.y >= 0 && loc.y < cols;
}

