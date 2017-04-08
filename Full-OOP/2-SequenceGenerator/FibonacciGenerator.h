#pragma once
#include "SequenceGenerator.h"

class FibonacciGenerator: 
	public SequenceGenerator
{
private:
	int startFibonacciNumber;
	void generateSequence();
	int	endFibonacciNumber;
public: //ctor
	FibonacciGenerator();
	FibonacciGenerator(int startFibonacciNumber, int endFibonacciNumber);
	FibonacciGenerator(const FibonacciGenerator& old); //copy ctor
	~FibonacciGenerator();	

public: // function

	std::string Getname(int index);
	double GetValue(int index);

	FibonacciGenerator& operator=(const FibonacciGenerator& old);

};

