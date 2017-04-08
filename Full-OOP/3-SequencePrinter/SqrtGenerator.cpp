#include "SqrtGenerator.h"

SqrtGenerator::SqrtGenerator()
{
}

SqrtGenerator::SqrtGenerator(int startInteger, int endInteger) :
	startInteger(startInteger),
	endInteger(endInteger)
{
	this->size_of_generator = this->endInteger - this->startInteger;
	this->name = new std::string[this->size_of_generator];
	this->values = new double[this->size_of_generator];
	generateSequence();
}

SqrtGenerator::SqrtGenerator(SqrtGenerator & old):
	startInteger(old.startInteger),
	endInteger(old.endInteger)
{
	this->name = new std::string[old.size_of_generator];
	this->values = new double[old.size_of_generator];
	
	for (size_t i = 0; i < old.size_of_generator; i++)
	{
		this->values[i] = old.values[i];
		this->name[i] = old.name[i];
	}
}

SqrtGenerator & SqrtGenerator::operator=(const SqrtGenerator & old)
{
	if(this != &old)
	{
		delete[] this->values;
		delete[] this->name;

		this->values = new double[old.size_of_generator];
		this->name = new std::string[old.size_of_generator];
		for (size_t i = 0; i < old.size_of_generator; i++)
		{
			this->values[i] = old.values[i];
			this->name[i] = old.name[i];
		}
		this->size_of_generator = old.size_of_generator;
		this->startInteger = old.startInteger;
		this->endInteger = old.endInteger;
		
	}
	return *this;
}

SqrtGenerator::~SqrtGenerator()
{
	delete[] this->values;
	delete[] this->name;
}

void SqrtGenerator::generateSequence()
{
	int index_ = 0;
	for (size_t i = this->startInteger; i < this->endInteger ; i++)
	{
		this->values[index_] = sqrt(i);
		this->name[index_] = "Sqrt(" + std::to_string(i) + ")";
		index_++;
	}

}

