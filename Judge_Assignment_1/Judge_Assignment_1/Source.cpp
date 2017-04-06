#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string ConvertToOutputFormat(int red, int green, int blue)
{
	string result;
	stringstream streamFirst;
	streamFirst << "#";
	if (red == 0)
	{
		streamFirst << "00";
	}
	else
	{
		streamFirst << hex << red;
	}
	if (green == 0)
	{
		streamFirst << "00";
	}
	else
	{
		streamFirst << hex << green;
	}

	if (blue == 0) 
	{
		streamFirst << "00";
	}
	else
	{
		streamFirst << hex << blue;
	}


	streamFirst << endl;
	
	return streamFirst.str();
}

int ConvertColor(string s)
{
	stringstream streamFirst;
	streamFirst << s;
	int value = 0;
	streamFirst >> hex >> value;
	return value;
}

int main()
{
	string str_first;
	string str_second;
	string red;
	string green;
	string blue;

	string red2;
	string green2;
	string blue2;


	cin >> str_first;
	cin >> str_second;

	red = str_first.substr(1, 2);
	green = str_first.substr(3, 2);
	blue = str_first.substr(5, 2);

	red2 = str_second.substr(1, 2);
	green2 = str_second.substr(3, 2);
	blue2 = str_second.substr(5, 2);

	int Red = (ConvertColor(red) + ConvertColor(red2)) / 2;
	int Green = (ConvertColor(green) + ConvertColor(green2)) / 2;
	int Blue = (ConvertColor(blue) + ConvertColor(blue2)) / 2;

	cout << setw(4)<<ConvertToOutputFormat(Red, Green, Blue);
	return 0;
}