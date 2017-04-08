#pragma once
#include <string>
class SequenceGenerator
{
protected:
	double * memory;
	std::string name;

	std::string Getname(int index);
	double getValue(int index);
	virtual void generateSequence() = 0;
};

