#pragma once
#include "SequenceGenerator.h"
#include <math.h>
class SqrtGenerator :
	public SequenceGenerator
{
private:
	int startInteger;
	int endInteger;
	void generateSequence();
public:
	SqrtGenerator();
	SqrtGenerator(int startInteger, int endInteger);
	SqrtGenerator(SqrtGenerator& old);
	SqrtGenerator& operator=(const SqrtGenerator& old);
	~SqrtGenerator();

};

