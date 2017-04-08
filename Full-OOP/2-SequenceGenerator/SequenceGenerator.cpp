#include "SequenceGenerator.h"

int SequenceGenerator::Size() const
{
	return this->size_of_generator;
}

std::string SequenceGenerator::Getname(int index) const
{
	return this->name[index];
}

double SequenceGenerator::getValue(int index) const
{
	return this->values[index];
}

