#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef int IntSmartArray;
typedef string StringSmartArray;
typedef char CharSmartArray;

class LineParser
{

private:
	string input_stream;

public:
	LineParser(const string& line) :
		input_stream(line)
	{
	}

	IntSmartArray * getNumbers(int& amount) const
	{
		istringstream stream(this->input_stream);
		int counterNumbers = 0;
		int numbers = 0;
		while (stream >> numbers)
		{
			counterNumbers++;
		}
		
		IntSmartArray * intArray = new IntSmartArray[counterNumbers];
		istringstream stream2(this->input_stream);
		counterNumbers = 0;
		while (stream2 >> numbers)
		{
			intArray[counterNumbers] = numbers;
			counterNumbers++;
		}

		amount = counterNumbers;
		return intArray;
	}

	StringSmartArray * getStrings(int& amount) const
	{
		istringstream stream(this->input_stream);
		int counterNumbers = 0;
		string numbers;
		while (stream >> numbers)
		{
			counterNumbers++;
		}

		StringSmartArray * stringArray = new StringSmartArray[counterNumbers];
		istringstream stream2(this->input_stream);
		counterNumbers = 0;
		while (stream2 >> numbers)
		{
			stringArray[counterNumbers] = numbers;
			counterNumbers++;
		}

		amount = counterNumbers;
		return stringArray;
	}

	CharSmartArray * getChars(int& amount) const
	{
		int counter = 0;
		for (auto i = this->input_stream.begin(); i != this->input_stream.end(); i++)
		{
			if (*i != ' ')
			{
				counter++;
			}
		}
		
		CharSmartArray * chars = new CharSmartArray[counter];
		counter = 0;
		for (auto i = this->input_stream.begin(); i != this->input_stream.end(); i++)
		{
			if (*i != ' ')
			{
				chars[counter] = *i;
				counter++;
			}
		}

		amount = counter;
		return chars;

	}

	void changeLine(const string& line)
	{
		this->input_stream = line;
	}

};

template <typename T>
void print_to_console(T &container, int &lenght) 
{
	for (size_t i = 0; i < lenght; i++)
	{
		cout <<"element[" << i << "] = " << container[i] << endl;
	}
}

int main()
{
	int get_lenght = 0;
	LineParser Parser("12 12 222 ");
	cout << "test 1" << endl;
	//test 1
	CharSmartArray * test_case_one = Parser.getChars(get_lenght);
	print_to_console(test_case_one,get_lenght);
	delete[] test_case_one;

	cout << "test 2" << endl;
	//test 2
	Parser.changeLine("5 10 5 55 22 11 22 33 333 555 121231 122 2");
	IntSmartArray * test_case_two = Parser.getNumbers(get_lenght);
	print_to_console(test_case_two, get_lenght);
	delete[] test_case_two;

	cout << "test 3" << endl;
	//test 3
	Parser.changeLine("5 10 5 55 22 11 22 33 333 555 121231 122 2");
	StringSmartArray *  test_case_three = Parser.getStrings(get_lenght);
	print_to_console(test_case_three, get_lenght);
	delete[] test_case_three;

	cout << "test 4" << endl;
	//test 4
	Parser.changeLine("");
	StringSmartArray * test_case_four = Parser.getStrings(get_lenght);
	print_to_console(test_case_four, get_lenght);
	delete[] test_case_four;
	
	cout << "test 5" << endl;
	//test 5
	Parser.changeLine("");
	IntSmartArray * test_case_fifth = Parser.getNumbers(get_lenght);
	print_to_console(test_case_fifth, get_lenght);
	delete[] test_case_fifth;

	cout << "test 6" << endl;
	//test 6
	Parser.changeLine("");
	CharSmartArray * test_case_six = Parser.getChars(get_lenght);
	print_to_console(test_case_six, get_lenght);
	delete[] test_case_six;

	cout << "test 7" << endl;
	//test 7
	Parser.changeLine("qwertyuiopasdfghjkl;zcvbn asdasdas 12123asdasd   1231 asdaas asdasdasd asda dsa da sddadad asdasd asda sdad asd asd ");
	StringSmartArray * test_case_seven = Parser.getStrings(get_lenght);
	print_to_console(test_case_seven, get_lenght);
	delete[] test_case_seven;

	cout << "test 8" << endl;
	//test 8
	Parser.changeLine(" 32 2 2 1112 232123123 1223 223123 12312 2323 22231 23123 222 3123 22 21 2 2223 233323 2323 2");
	IntSmartArray * test_case_eight = Parser.getNumbers(get_lenght);
	print_to_console(test_case_eight, get_lenght);
	delete[] test_case_eight;

	cout << "test 9" << endl;
	//test 9
	Parser.changeLine("cs sa asss aasd ss asd dasd asdas a123 as 13aq q a\ ;';s s23 as2ese ");
	CharSmartArray * test_case_nine = Parser.getChars(get_lenght);
	print_to_console(test_case_nine, get_lenght);
	delete[] test_case_nine;

	cout << "test 10" << endl;
	//test 10
	Parser.changeLine("cs sa asssssss aasd ss asd dasd asdas a123 as 13aq q a\\ ;';s s23 as2ese asdasd");
	StringSmartArray * test_case_ten = Parser.getStrings(get_lenght);
	print_to_console(test_case_ten, get_lenght);
	delete[] test_case_ten;

	return 0;
}