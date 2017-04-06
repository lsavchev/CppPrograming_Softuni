#include <string>
#include <iostream>

using namespace std;

int occurences(const string& text, const string& search)
{
	int match_case = 0;
	int case_lenght = search.size();

	for (size_t i = 0; i < text.size(); )
	{		
		if (text.compare(i, case_lenght, search) == 0)
		{
			match_case++;
			i += search.size();
		}
		else
		{
			i++;
		}
	}

	return match_case;
}

int main()
{
	string text = "Write a function int occurences(const string& text, const string& search) which returns the number of times search is contained in text";
	string search = "on";
	cout <<occurences(text, search) << endl; 

	return 0;
}