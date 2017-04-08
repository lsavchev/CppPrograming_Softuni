#include "SequencePrinterToFile.h"

SequencePrinterToFile::SequencePrinterToFile(SequenceGenerator & seq, std::string f_name)
	: objSeq(seq),
	objFile(f_name,std::ios::app)
{
}

SequencePrinterToFile::~SequencePrinterToFile()
{
}

void SequencePrinterToFile::print()
{
	format_output();
}

void SequencePrinterToFile::setSequence(const SequenceGenerator & sequence)
{
	this->objSeq = sequence;
}

void SequencePrinterToFile::format_output()
{

	this->objFile << "Names: ";
	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		this->objFile << this->objSeq.Getname(i) << " ";
	}
	this->objFile << "Values: ";
	for (size_t i = 0; i < this->objSeq.Size(); i++)
	{
		this->objFile << this->objSeq.getValue(i) << " ";
	}
	this->objFile << std::endl;
}