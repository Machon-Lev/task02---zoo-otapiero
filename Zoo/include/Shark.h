#pragma once
#include "Animal.h"
class Shark : public Animal
{
	public:
	Shark(const std::string& name, const Location& location);
	void printDetails() override;
	char getInitial() override;
	virtual void step() override;
	~Shark() override;

};