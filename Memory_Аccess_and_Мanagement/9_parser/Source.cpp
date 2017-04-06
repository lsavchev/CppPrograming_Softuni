#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int * parseNumbers(const string& str, int& resultLength)
{
	std::istringstream inputStream(str);

	int numbers = 0;
	
	int counter = 0;
	while (inputStream >> numbers) // не се сещам за по хитър начин да разбера колко са числата в стринга
	{
		counter++;
	}
	int * result = new int[counter];
	std::istringstream inputStream2(str);
	counter = 0;
	while (inputStream2 >> numbers)
	{
		 result[counter] = numbers ;
		 counter++;
	}
	resultLength = counter;
	
	return result;
}

string IntToString(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}

int main()
{
	string input;
	int arr_lenght = 0;
	int input_lines;
	int sum = 0;
	int * expected_pointer = NULL;

	getline(cin, input);
	std::istringstream inputStream2(input);
	inputStream2 >> input_lines;


	
	string output("(sum of ");
	for (size_t i = 0; i < input_lines; i++)
	{
		getline(cin, input);
		expected_pointer = parseNumbers(input, arr_lenght);

		if (i != 0)
		{
			output.append("and ");
		}

		for (size_t j = 0; j < arr_lenght; j++)
		{
			sum += expected_pointer[j];
			output.append(IntToString(expected_pointer[j]) + " ");
		}

		delete[] expected_pointer;
	}

	output.erase(output.end() - 1, output.end());
	output.append("):" + IntToString(sum));

	cout << output << endl;

	return 0;
}