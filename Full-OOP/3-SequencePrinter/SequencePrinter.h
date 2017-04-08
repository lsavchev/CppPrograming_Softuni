#pragma once
#include "SequenceGenerator.h"
class SequencePrinter
{
public:
	virtual void print() = 0;
	virtual void setSequence(const SequenceGenerator& sequence) = 0;
};

