#include <iostream>
#include <string>

using namespace std;

class StringFormatter
{
private:
	string &formatString;

	const string formatPrefic;

	int check_input_matches()
	{
		bool match = true;
		std::size_t found = 0;
		int resultMatches = 0;

		found = this->formatString.find(this->formatPrefic, found);
		if (found == 0)
		{
			resultMatches++;
		}
		
		while (found != string::npos)
		{
			if (found)
			{
				resultMatches++;
			}

			found = this->formatString.find(this->formatPrefic, found + this->formatPrefic.size());
			
		}

		return resultMatches;
	}

	void format_string(string insertArr[], int insertArrSize)
	{
		bool match = true;
		std::size_t found = 0;
		int resultMatches = 0;
		string position_string_format;
		int number_of_position_digits = 0;
		int index_in_array = 0;

		found = this->formatString.find(this->formatPrefic, found );

		number_of_position_digits = found + this->formatPrefic.size();
		position_string_format = this->formatString[number_of_position_digits];
		number_of_position_digits++;
		while (isdigit(this->formatString[number_of_position_digits]))
		{
			position_string_format.append(1, this->formatString[number_of_position_digits]);
			number_of_position_digits++;
		}
		index_in_array = stoi(position_string_format);

		while (found != string::npos)
		{
			if (index_in_array < (insertArrSize ))
			{
				this->formatString.replace(found, this->formatPrefic.size() + position_string_format.size(), insertArr[index_in_array]);
			}
			else
			{
				this->formatString.replace(found, this->formatPrefic.size() + position_string_format.size(), string());
			}
			

			found = this->formatString.find(this->formatPrefic, found + 1/* this->formatPrefic.size()*/);
			if (found != string::npos)
			{
				number_of_position_digits = found + this->formatPrefic.size();
				position_string_format = this->formatString[number_of_position_digits];
				number_of_position_digits++;
				while (isdigit(this->formatString[number_of_position_digits]))
				{
					position_string_format.append(1, this->formatString[number_of_position_digits]);
					number_of_position_digits++;
				}
				index_in_array = stoi(position_string_format);
			}
		}
	}

	void format_integer(int insertArr[], int insertArrSize)
	{
		bool match = true;
		std::size_t found = 0;
		int resultMatches = 0;
		string position_string_format;
		int number_of_position_digits = 0;
		int index_in_array = 0;

		found = this->formatString.find(this->formatPrefic, found);

		number_of_position_digits = found + this->formatPrefic.size();
		position_string_format = this->formatString[number_of_position_digits];
		number_of_position_digits++;
		while (isdigit(this->formatString[number_of_position_digits]))
		{
			position_string_format.append(1, this->formatString[number_of_position_digits]);
			number_of_position_digits++;
		}
		index_in_array = stoi(position_string_format);

		while (found != string::npos)
		{
			if (index_in_array <= insertArrSize)
			{
				this->formatString.replace(found, this->formatPrefic.size() + position_string_format.size(), to_string(insertArr[index_in_array]));
			}
			else
			{
				this->formatString.replace(found, this->formatPrefic.size() + position_string_format.size(), string());
			}


			found = this->formatString.find(this->formatPrefic, found + 1/* this->formatPrefic.size()*/);
			if (found != string::npos)
			{
				number_of_position_digits = found + this->formatPrefic.size();
				position_string_format = this->formatString[number_of_position_digits];
				number_of_position_digits++;
				while (isdigit(this->formatString[number_of_position_digits]))
				{
					position_string_format.append(1, this->formatString[number_of_position_digits]);
					number_of_position_digits++;
				}
				index_in_array = stoi(position_string_format);
			}
		}
	}

public:
	StringFormatter(string& stringToFormat, const string& formatPrefix) :
		formatString(stringToFormat),
		formatPrefic(formatPrefix)
	{
	}

	void format(string insertArr[], int insertArrSize)
	{
		std::size_t found = 0;
		found = check_input_matches();
		if (found < insertArrSize)
		{
			throw "Wrong Input...";
			return;
		}
			

		format_string(insertArr, insertArrSize);
	}

	void format(int insertArr[], int insertArrSize)
	{
		std::size_t found = 0;
		found = check_input_matches();
		if (found < insertArrSize)
		{

			throw "Wrong Input...";
			return;
		}


		format_integer(insertArr, insertArrSize);
	}

};

int main()
{
	

	string s1 = "Dear *:0, Our company *:1 wants to make you a Donation Of *:2 Million *:3 in good faith.Please send us a picture of your credit card";
	string s2 = "99 + |0 =  |1  Excellent math !!!";
	string s3 = "*0*1*2*3*4*5*6*7*8*9";
	string s4 = "We love to play |ASD1. Noone can stop |ASD0";
	string s5 = "This ?:0 will ?:1 be ?:2 empty ?:3 array test";
	string s6 = "Default value of array is aloooo0 ";
	string s7 = "word0 word1 word2 word3 word4 word5 word6, word7 word8 word9 word10 - ako poslednata duma e \" word10 \" znachi vchisko e 6";

	StringFormatter formatter1(s1, "*:");
	StringFormatter formatter2(s2, "|");
	StringFormatter formatter3(s3, "*");
	StringFormatter formatter4(s4, "|ASD");
	StringFormatter formatter5(s5, "?:");
	StringFormatter formatter6(s6, "aloooo");
	StringFormatter formatter7(s7, "word");
	try 
	{
		formatter1.format(new string[4]{ "Ben Dover", "Totally Legit NonSpam Ltd", "13", "Leva" },4);
		cout << s1 << endl;

		formatter2.format(new int[2]{ 101, 200 }, 2);
		cout << s2 << endl;

		formatter3.format(new int[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 10);
		cout << s3 << endl;

		formatter4.format(new string[2]{ "us","games" }, 2);
		cout << s4 << endl;

		//formatter4.format(new string[3]{ "us","games", "Error" }, 3);  //uncomment to check error input
		//cout << s4 << endl;

		//formatter3.format(new int[11]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 11); //uncomment to check error input
		//cout << s3 << endl;

		formatter5.format(new string[4]{ "","", "", "" }, 4); // empty arrays will add one space. No clue should they add space or delete the formatprefix, choice to add space.
		cout << s5 << endl;

		formatter6.format(new int[1]{ }, 1); // empty arrays will add one space. No clue should they add space or delete the formatprefix, choice to add space.
		cout << s6 << endl;

		formatter7.format(new string[12]{"Ne", "znam", "zashto", "pravq","tozu", "test", "case", "no", "shte", "go", "napravq", "" }, 12); // empty arrays will add one space. No clue should they add space or delete the formatprefix, choice to add space.
		cout << s7 << endl;
	}
	catch(const char *msg)
	{
		cout << msg;
	}

	

	return 0;
}