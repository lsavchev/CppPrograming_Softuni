#pragma once
#include "SequencePrinter.h"
#include <fstream>
class SequencePrinterToFile :
	public SequencePrinter
{
private:
	SequenceGenerator& objSeq;
	void format_output();
	std::fstream objFile;

public:
	SequencePrinterToFile(SequenceGenerator& seq, std::string f_name);
	~SequencePrinterToFile();

	// Inherited via SequencePrinter
	virtual void print() override;
	virtual void setSequence(const SequenceGenerator & sequence) override;
};

