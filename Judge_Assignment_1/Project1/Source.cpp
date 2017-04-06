#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int sum(int array[],int startIndex,int endIndex)
{
	int sum = 0;
	while (startIndex != endIndex)
	{
		sum += array[startIndex];
		startIndex++;
	}
		
	return sum;
}

int avg(int array[], int startIndex, int endIndex)
{
	return sum(array, startIndex, endIndex) / (endIndex - startIndex);
}

int min(int array[], int startIndex, int endIndex)
{
	return *min_element(array+startIndex, array +endIndex);
}
	

int max(int array[], int startIndex, int endIndex)
{
	return *max_element(array + startIndex, array + endIndex);
}

int operation(int array[], int startIndex, int endIndex, int funcParam)
{
	int result = 0;
	switch (funcParam)
	{
	case 0: 
		result = sum(array, startIndex, endIndex);
		break;
	case 1: 
		result = avg(array, startIndex, endIndex);
		break;
	case 2: 
		result = min(array, startIndex, endIndex);
		break;
	case 3: 
		result = max(array, startIndex, endIndex);
		break;
	}

	return result;
}


int main()
{
	string input;

	getline(cin, input);

	stringstream inputStream(input);

	int counter = 0;
	int count;
	while (inputStream >> count)
	{
		counter++;
	}
	stringstream inputStream2(input);
	int * array_numbers = new int[counter];
	
	for (size_t i = 0; i < counter; i++)
	{
		inputStream2 >> array_numbers[i];
	}
	int opearations = 0;
	cin >> opearations;

	map<string, int> command;
	map<string, int>::iterator it = command.begin();
	for (size_t i = 0; i < opearations; i++)
	{
		string currentCommand;
		int number_of_command = 0;

		cin >> currentCommand;
		cin >> number_of_command;
		command.insert(pair<string, int>(currentCommand, number_of_command));
	}
	cin.ignore();
	string currentCommand;
	getline(cin, currentCommand);


	int C = 0;
	int start_index = 0;
	int end_index = 0;
	string commandString;
	ostringstream output("");
	
	output << "{";
	int commands_passed = 0;
	while (currentCommand != "end")
	{		
		commands_passed++;
		stringstream splitInput(currentCommand);
		splitInput >> commandString >> start_index >> end_index;
				
		for (it = command.begin(); it != command.end(); ++it)
		{
			if (it->first == commandString)
			{
				int res = operation(array_numbers, start_index, end_index, it->second);
				output << it->first << "(" << start_index << "," << end_index << ")=" << res<<",";
			}
		}

		splitInput.str("");
		splitInput.clear();
		getline(cin, currentCommand);
	}
	string outout = output.str();
	outout.erase(outout.size() - 1);
	ostringstream startot("");
	outout.append("}");

	startot << "[" << commands_passed << "]";
	string finalend = startot.str() + outout;
	cout << finalend <<endl;
	return 0;
}