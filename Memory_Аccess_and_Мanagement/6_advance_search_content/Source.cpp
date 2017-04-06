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
	string text;
	string search;

	cout << "Write text content: ";
	getline(cin, text);
	cout << "Write what you want to search in content: ";
	getline(cin, search);

	cout <<"Match: " <<occurences(text, search) << endl;

	return 0;
}