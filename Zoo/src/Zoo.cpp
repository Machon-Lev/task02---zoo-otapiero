#include "Zoo.h"


// Zoo constructor 
Zoo::Zoo()
{
	// initialize the zoo
	create("Lion", "Simba");
	create("Lion", "Mufasa");
	create("Shark", "Jaws");
	create("ClownFish", "Nemo");

	


}

// Zoo destructor
Zoo::~Zoo()
{
	// Delete all animals in the animal_map
	for (int i = 0; i < animal_map.size(); i++)
	{
		delete animal_map[i];
	}
	if (!is_srand_initiallized) {
		srand(time(NULL));
		is_srand_initiallized = true;
	}

}
/**/void Zoo::run()
{
	
	// print welcome message and the map of the zoo and then a switch menu to choose the next action
	std::cout << "Welcome to the Zoo!" << std::endl;
	std::cout << std::endl;
	help();
	std::cout << std::endl;
	std::cout << "Here is the map of the Zoo:" << std::endl;
	printMap();
	std::cout << std::endl;
	printList();

	std::cout << "Please choose one of the options above." << std::endl;
	std::cout << std::endl;


	// get the user's choice and do a loop
	while (true)
	{
		std::cout << "Please enter your choice:" << std::endl;
		std::string choice;

		std::cin >> choice;
		if (choice == "stop")
		{
			int number_of_animal;

			std::cout << "Please enter the animal number to stop:" << std::endl;
			std::cin >> number_of_animal;
			if (number_of_animal < 0 || number_of_animal > animal_map.size())
			{
				std::cout << "Invalid animal number! try again or enter help." << std::endl;
			}
			else
				stop(number_of_animal);

		}
		else if (choice == "move")
		{
			int number_of_animal;

			std::cout << "Please enter the animal number to move:" << std::endl;
			std::cin >> number_of_animal;
			if (number_of_animal < 0 || number_of_animal > animal_map.size())
			{
				std::cout << "Invalid animal number! try again or enter help" << std::endl;
			}
			else
				move(number_of_animal);

		}
		else if (choice == "create")
		{
			std::string animal_type, name;

			std::cout << "Please enter the animal type and name:" << std::endl;
			std::cin >> animal_type >> name;
			create(animal_type , name);
		}
		else if (choice == "delete")
		{
			int number_of_animal;

			std::cout << "Please enter the animal number to delete:" << std::endl;
			std::cin >> number_of_animal;
			if (number_of_animal <= 0 || number_of_animal > animal_map.size())
			{
				std::cout << "Invalid animal number! try again or enter help." << std::endl;				
			}
			else
				del(number_of_animal);

		}
		else if (choice == "delAll")
		{
			std::string animal_type;

			std::cout << "Please enter the animal type to delete:" << std::endl;
			std::cin >> animal_type;
			if (animal_type != "Lion" && animal_type != "Shark" && animal_type != "ClownFish")
			{
				std::cout << "Invalid animal type! try again or enter help." << std::endl;
			}
			else
			 delAll(animal_type);
		}
		else if (choice == "help")
		{
			help();
		}
		else if (choice == ".")
		{
			step();
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			break;
		}
		printMap();
		printList();
	}

}
void Zoo::stop(int animal_number)
{
	if (animal_number <= 0 || animal_number >animal_map.size())
	{
		std::cout << "Invalid animal number! try again or enter help." << std::endl;
		return;
	}
	animal_map[animal_number - 1]->stop();

}

void Zoo::move(int animal_number)
{
	if (animal_number <= 0 || animal_number > animal_map.size())
	{
		std::cout << "Invalid animal number! try again or enter help." << std::endl;
		return;
	}
	animal_map[animal_number - 1]->move();
}

void Zoo::create(const std::string& animal_type,const  std::string& name)
{
	if (animal_type == "" || name == "")
	{
		std::cout << "Invalid input. Please try again or enter help." << std::endl;
		return;
	}
	if (animal_type == "Lion")
	{
		animal_map.push_back(new Lion(name, getRandomLocation()));
	}
	else if (animal_type == "Shark")
	{
		animal_map.push_back(new Shark(name, getRandomLocation()));
	}
	else if (animal_type == "ClownFish")
	{
		animal_map.push_back(new ClownFish(name, getRandomLocation()));
	}
	else
	{
		std::cout << "Invalid input. Please try again or enter help." << std::endl;
	}
	
}

void Zoo::del(int number)
{
	if (number <= 0 || number > animal_map.size())
	{
		std::cout << "Invalid animal number! try again" << std::endl;
		return;
	}
	animal_map.erase(animal_map.begin() + (number - 1));
}

void Zoo::delAll(const std::string& animal_type)
{
	if (animal_type != "Lion" && animal_type != "Shark" && animal_type != "ClownFish")
	{
		std::cout << "Invalid animal type! Try again." << std::endl;
		return;
	}

	for (auto it = animal_map.begin(); it != animal_map.end(); )
	{
		if ((*it)->getInitial() == animal_type[0])
		{
			delete* it;
			it = animal_map.erase(it);
		}
		else
		{
			++it;
		}
	}
}



void Zoo::help() const
{
	// help the user understand the different option and how to use them
	std::cout << "The following commands are available:" << std::endl;
	std::cout << "stop - stop one animal from moving until move command is used" << std::endl;
	std::cout << "parameters needed: animal number in the list" << std::endl << std::endl;

	std::cout << "move - give to an animal to move after each turn until stop command is given" << std::endl;
	std::cout << "parameters needed: animal number in the list" << std::endl << std::endl;

	std::cout << "create - create a new animal in the zoo" << std::endl;
	std::cout << "parameters needed: animal type and name" << std::endl << std::endl;

	std::cout << "delete - delete an animal from the zoo" << std::endl;
	std::cout << "parameters needed: animal number in the list" << std::endl << std::endl;

	std::cout << "delAll - delete all animals of a specific type from the zoo" << std::endl;
	std::cout << "parameters needed: animal type" << std::endl << std::endl;

	std::cout << ". - advance the simulation by one turn" << std::endl << std::endl;

	std::cout << "help - print this help message" << std::endl << std::endl;
	std::cout << "exit - exit the program" << std::endl << std::endl;


}

void Zoo::step()
{
	// activate step() for all the animals in th animal_map
	for (int i = 0; i < animal_map.size(); i++)
	{
		animal_map[i]->step();
	}
	
}
void Zoo::printMap() const
{
	// print the map of the zoo 20*40
	// for animals use getInitial() to get initial
	for (int i = 0; i < 42; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << '#';
		for (int j = 0; j < 40; j++)
		{
			bool animal_found = false;
			for (Animal* animal : animal_map) {
				
				if (animal->getLocation().x == i && animal->getLocation().y == j) {
					std::cout << animal->getInitial();
					animal_found = true;
					break;
				}
			}
			if (!animal_found) {
				std::cout << " ";
			}
		}
		std::cout << "#" << std::endl;
	}
	for (int i = 0; i < 42; i++) {
		std::cout  << "#";
	}
	std::cout << std::endl;

}
void Zoo::printList() const
{
	for (int i = 0; i < animal_map.size(); i++)
	{
		std::cout << i+1<< " - "<< animal_map[i]->getInitial() << std::endl;
	}

}
Location Zoo::getRandomLocation()
{
	return Location(rand() % 20, rand() % 40);
}
bool Zoo::is_srand_initiallized = false;
