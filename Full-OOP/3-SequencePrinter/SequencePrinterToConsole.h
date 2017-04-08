#pragma once
#include "SequencePrinter.h"
class SequencePrinterToConsole :
	public SequencePrinter
{
private:
	SequenceGenerator& objSeq;
	void format_output();
public:
	SequencePrinterToConsole(SequenceGenerator& seq);

	~SequencePrinterToConsole();

	// Inherited via SequencePrinter
	virtual void print() override;
	virtual void setSequence(const SequenceGenerator & sequence) override;
};

