#include "Shark.h"

Shark::Shark(const std::string& name, const Location& location) : Animal(name,  location)
{
}

void Shark::printDetails()
{
	std::cout << "Shark - " << name << " Location:" << location << std::endl;
}

char Shark::getInitial()
{
	return 'S';
}

void Shark::step()
{
	if (canMove)
	{
		int rand = std::rand() % 8;
		Location loc_shift;
		switch (rand)
		{
		case 0:
			loc_shift = Location(0, 5);
			break;
		case 1:
			loc_shift = Location(0, -5);
			break;
		case 2:
			loc_shift = Location(5, 0);
			break;
		case 3:
			loc_shift = Location(-5, 0);
			break;
		case 4:
			loc_shift = Location(5, 5);
			break;
		case 5:
			loc_shift = Location(-5, -5);
			break;
		case 6:
			loc_shift = Location(5, -5);
			break;
		case 7:
			loc_shift = Location(-5, 5);
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

Shark::~Shark()
{
}
