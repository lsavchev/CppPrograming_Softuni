#include "SequencePrinterToString.h"

SequencePrinterToString::SequencePrinterToString(SequenceGenerator & seq, std::string & obj) :
	objSeq(seq),
	objStr(obj)
{
}

SequencePrinterToString::~SequencePrinterToString()
{
}

void SequencePrinterToString::print()
{
	format_output();
}

void SequencePrinterToString::setSequence(const SequenceGenerator & sequence)
{
	this->objSeq = sequence;
}

void SequencePrinterToString::format_output()
{
	
	this->objStr.append("Names: ");

	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		this->objStr.append(this->objSeq.Getname(i));
		this->objStr.append(" ");
	}
	this->objStr.append("Values: ");
	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		this->objStr.append(std::to_string(this->objSeq.getValue(i)));
		this->objStr.append(" ");
	}
	std::cout << std::endl;
}