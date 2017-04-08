#include "SequencePrinterToConsole.h"

void SequencePrinterToConsole::format_output()
{
	std::cout << "Names: ";
	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		std::cout << this->objSeq.Getname(i) << " ";
	}
	std::cout << "Values: ";
	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		std::cout << this->objSeq.getValue(i) << " ";
	}
	std::cout << std::endl;
}

SequencePrinterToConsole::SequencePrinterToConsole(SequenceGenerator& seq):
	objSeq(seq)
{
}

SequencePrinterToConsole::~SequencePrinterToConsole()
{
}

void SequencePrinterToConsole::print()
{
	format_output();
}

void SequencePrinterToConsole::setSequence(const SequenceGenerator & sequence)
{
	this->objSeq = sequence;
}
