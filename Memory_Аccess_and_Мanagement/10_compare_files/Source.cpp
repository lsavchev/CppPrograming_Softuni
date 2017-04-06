#include <string>
#include <iostream>
#include <sstream>
#include <fstream> 

#define ERROR 1

using namespace std;

int main()
{
	int current_line = 0;
	
	string first_file_name("first.txt");
	string second_file_name("second.txt");

	ifstream FirstStream(first_file_name);
	ifstream SecondStream(second_file_name);

	string line_content_first_file;
	string line_content_second_file;

	if (!FirstStream || !SecondStream)
	{
		cout << "File doesn`t exist!!!" << endl;
		return ERROR;
	}

	if (FirstStream.eof() || SecondStream.eof())
	{
		cout << "File is empty!!!" << endl;
		return ERROR;
	}

	while (!FirstStream.eof() && !SecondStream.eof())
	{
		getline(FirstStream, line_content_first_file);
		getline(SecondStream, line_content_second_file);
 		
		if (line_content_first_file.compare(line_content_second_file) != 0)
		{
			cout << "Files not match at line " << current_line << endl;
			return ERROR;
		}
		current_line++;
	}

	if (!FirstStream.eof() && !SecondStream.eof())
	{
		cout << "One of files have more lines, Unsuccessful match" << endl;
		return ERROR;
	}

	cout << "Successful match !!!" << endl;
	return 0;
}