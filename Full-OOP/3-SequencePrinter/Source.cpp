#include <iostream>
#include "SequencePrinter.h"
#include "SequenceGenerator.h"
#include "SequencePrinterToConsole.h"
#include "SequencePrinterToString.h"
#include "SequencePrinterToFile.h"
#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"
#include <fstream>


int main()
{
	FibonacciGenerator f(3,6);
	SqrtGenerator sqrtt(1, 9);
	SequencePrinterToFile file(f, "output.txt");
	file.print();
	SequencePrinterToConsole seq(f);
	std::string dotsAtStart(".....");

	SequencePrinterToString seqStr(sqrtt, dotsAtStart);
	seqStr.print();
	seq.print();
	seq.setSequence(sqrtt);
	seq.print();
	return 0;
}