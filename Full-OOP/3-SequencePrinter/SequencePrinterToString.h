#pragma once
#include "SequencePrinter.h"
class SequencePrinterToString :
	public SequencePrinter
{
private:
	SequenceGenerator& objSeq;
	std::string &objStr;
	void format_output();
public:
	SequencePrinterToString(SequenceGenerator& seq, std::string&obj);
	~SequencePrinterToString();

	// Inherited via SequencePrinter
	virtual void print() override;
	virtual void setSequence(const SequenceGenerator & sequence) override;
};

