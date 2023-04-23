#pragma once

#include "Animal.h"
#include "Location.h"

class ClownFish : public Animal
{
public:
	ClownFish(const std::string& name, const Location& location);
	void printDetails() override;
	char getInitial() override;
	virtual void step() override;
	~ClownFish() override;

};
