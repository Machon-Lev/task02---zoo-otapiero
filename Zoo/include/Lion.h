#pragma once
#include "Animal.h"
#include "Location.h"

class Lion : public Animal
{
public:
	Lion(const std::string& name, const Location& location);
	void printDetails() override;
	char getInitial() override;
	virtual void step() override;
	~Lion() override;
	void turnHorizontally() override;
private:
	int direction = 1;




};

