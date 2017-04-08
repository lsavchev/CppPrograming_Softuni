#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator()
{
}

FibonacciGenerator::FibonacciGenerator(int startFibonacciNumber, int	endFibonacciNumber) :
	startFibonacciNumber(startFibonacciNumber),
	endFibonacciNumber(endFibonacciNumber)
{
	this->size_of_generator = endFibonacciNumber - startFibonacciNumber;
	this->name = new std::string[this->size_of_generator];
	this->values = new double[this->size_of_generator];
	generateSequence();
}

FibonacciGenerator::FibonacciGenerator(const FibonacciGenerator& old) :
	startFibonacciNumber(old.startFibonacciNumber),
	endFibonacciNumber(old.endFibonacciNumber)
{
	this->size_of_generator = old.size_of_generator;
	this->values = new double[old.size_of_generator];
	this->name = new std::string[old.size_of_generator];

	for (size_t i = 0; i <old.size_of_generator; i++)
	{
		this->values[i] = old.values[i];
		this->name[i] = old.name[i];
	}
}

FibonacciGenerator::~FibonacciGenerator()
{
	delete[] this->values;
	delete[] this->name;
}


FibonacciGenerator & FibonacciGenerator::operator=(const FibonacciGenerator & old)
{
	if (this != &old)
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
		this->startFibonacciNumber = old.startFibonacciNumber;
		this->endFibonacciNumber = old.endFibonacciNumber;
	}
	return *this;
}

void FibonacciGenerator::generateSequence()
{

	int first = 0;
	int second = 1;
	int next = 0;
	int count_fibonachi_index = 0;
	for (int c = 0; c < this->endFibonacciNumber; c++)
	{
		if (c <= 1)
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}

		if (c >= this->startFibonacciNumber)
		{
			this->values[count_fibonachi_index] = next;
			this->name[count_fibonachi_index] = "Fibonacchi " + std::to_string(c);
			count_fibonachi_index++;
		}

	}

}


//std::string FibonacciGenerator::Getname(int index)
//{
//	try
//	{
//		if(index < this->size_of_generator)
//		{
//			int a = 0;
//			a = this->memory[index];
//			return this->name.replace(10, 1, std::to_string(a));
//
//		}else
//		{
//			return std::string();
//		}
//	}
//	catch (std::exception ex)
//	{
//		return std::string();
//	}
//}

//double FibonacciGenerator::GetValue(int index) const
//{
//	if (index < this->size_of_generator)
//	{
//		return this->values[index];
//	}
//	else
//	{
//		return -1;
//	}
//}

