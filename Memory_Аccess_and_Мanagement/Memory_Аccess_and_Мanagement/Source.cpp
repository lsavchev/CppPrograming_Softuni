#include <iostream>

#define BUFFER_SIZE			100


bool compArr(int arr1, int arr2)
{
	return arr1 == arr2;
}

int main()
{
	auto array_lenght = 0;

	// нямаше по условие какъв да е размера на входните масиви, за това ще питам за тях.
	std::cout << "Enter array`s lenth: ";
	std::cin >> array_lenght;

	int arr1[BUFFER_SIZE] = {};
	int arr2[BUFFER_SIZE] = {};

	std::cout << "Enter elements of first array ";
	for (size_t i = 0; i < array_lenght; i++)
	{
		std::cin >> arr1[i];
	}
	std::cout << "Enter elements of second array ";

	for (size_t i = 0; i < array_lenght; i++)
	{
		std::cin >> arr2[i];
	}

	for (size_t i = 0; i < array_lenght; i++)
	{
		if (compArr(arr1[i], arr2[i]))
		{
			std::cout << "element[" << i << "] equal."<< std::endl;
		}
		else
		{
			std::cout << "element[" << i << "] not equal." << std::endl;
		}
	}
	
	return 0;
}
