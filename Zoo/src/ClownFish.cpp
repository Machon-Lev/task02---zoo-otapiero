#include "ClownFish.h"

ClownFish::ClownFish(const std::string& name, const Location& location) : Animal(name, location)
{
}

void ClownFish::printDetails()
{
	std::cout << "ClownFish - " << name << " Location:" << location << std::endl;
}

char ClownFish::getInitial()
{
	return name[0];
}

void ClownFish::step()
{
	// Clown Fish move one step each turn in a random direction between 8 directions (up, down, left, right, and the 4 diagonals).
	if (canMove)
	{
		int rand = std::rand() % 8;
		Location loc_shift;
		switch (rand)
		{
		case 0:
			loc_shift = Location(0, 1);
			break;
		case 1:
			loc_shift = Location(0, -1);
			break;
		case 2:
			loc_shift = Location(1, 0);
			break;
		case 3:
			loc_shift = Location(-1, 0);
			break;
		case 4:
			loc_shift = Location(1, 1);
			break;
		case 5:
			loc_shift = Location(-1, -1);
			break;
		case 6:
			loc_shift = Location(1, -1);
			break;
		case 7:
			loc_shift = Location(-1, 1);
			break;
		default:
			break;

		}
		location += loc_shift;
		if (!is_within_bounds(location))
		{
			location -= loc_shift;
			step();
		}
	}
}

ClownFish::~ClownFish()
{
}


