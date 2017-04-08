#include <iostream>
#include <windows.h>
#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"
// fibonachi chislata shte rabotqt samo do razmera na int ne s po golqm.
int main()
{
	FibonacciGenerator f(3,6);
	SqrtGenerator s(4, 10);

	for (size_t i = 0; i < f.Size(); i++)
	{
		std::cout << f.Getname(i) << std::endl;
		std::cout << f.getValue(i) << std::endl;
	}
	for (size_t i = 0; i < s.Size(); i++)
	{
		std::cout << s.Getname(i) << std::endl;
		std::cout << s.getValue(i) << std::endl;
	}
	//for (int ind1 = 0; ind1 < 1000000; ind1++) {

	//	for (int ind2 = 0; ind2 < 1000000; ind2++) {

	//		FibonacciGenerator g(1, 100);

	//		FibonacciGenerator copyConstructed(g);

	//		FibonacciGenerator copyAssigned(1, 5);

	//		copyAssigned = g;

	//		// print copyAssigned and copyConstructed to see they are correct

	//		// or just have a function which checks each of their values
	//		std::cout << g.Getname(ind2) << std::endl;
	//		std::cout << copyAssigned.Getname(ind2) << std::endl;
	//		Sleep(500);
	//	}

	//}

	return 0;
}
