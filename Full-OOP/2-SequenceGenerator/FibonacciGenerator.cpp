#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator()
{
}

FibonacciGenerator::FibonacciGenerator(const FibonacciGenerator& old) :
	startFibonacciNumber(old.startFibonacciNumber),
	endFibonacciNumber(old.endFibonacciNumber)
{
	this->memory = new double[old.endFibonacciNumber - startFibonacciNumber];
	this->name = old.name;
	for (size_t i = 0; i <(old.endFibonacciNumber - startFibonacciNumber); i++)
	{
		this->memory[i] = old.memory[i];
	}
}

FibonacciGenerator::FibonacciGenerator(int startFibonacciNumber, int	endFibonacciNumber) :
	startFibonacciNumber(startFibonacciNumber),
	endFibonacciNumber(endFibonacciNumber)
{
	name = "Fibonacci ";
	this->memory = new double[endFibonacciNumber - startFibonacciNumber];
	generateSequence();
}

std::string FibonacciGenerator::Getname(int index)
{
	try
	{
		if(index < this->endFibonacciNumber - this->startFibonacciNumber)
		{
			int a = 0;
			a = this->memory[index];
			return this->name.replace(10, 1, std::to_string(a));

		}else
		{
			return std::string();
		}
	}
	catch (std::exception ex)
	{
		return std::string();
	}
}

double FibonacciGenerator::GetValue(int index)
{
	if (index < this->endFibonacciNumber - this->startFibonacciNumber)
	{
		return this->memory[index];
	}
	else
	{
		return -1;
	}
}

FibonacciGenerator & FibonacciGenerator::operator=(const FibonacciGenerator & old)
{
	if (this != &old)
	{
		delete[] this->memory;

		this->memory = new double[old.endFibonacciNumber - startFibonacciNumber];

		for (size_t i = 0; i <(old.endFibonacciNumber - startFibonacciNumber); i++)
		{
			this->memory[i] = old.memory[i];
		}

		this->startFibonacciNumber = old.startFibonacciNumber;
		this->endFibonacciNumber = old.endFibonacciNumber;
		this->name = old.name;
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
			memory[count_fibonachi_index] = next;
			count_fibonachi_index++;
		}
		
	}

}

FibonacciGenerator::~FibonacciGenerator()
{
	delete[] this->memory;
}
