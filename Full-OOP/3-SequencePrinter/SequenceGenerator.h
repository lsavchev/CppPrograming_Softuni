#pragma once
#include <string>
#include <iostream>
class SequenceGenerator
{

protected:
	int size_of_generator;
	double * values;
	std::string * name;
public:

	int Size() const;

	std::string Getname(int index) const;
	double getValue(int index) const;
	virtual void generateSequence() = 0;
};

