#include <string>
#include <iostream>

using namespace std;

void find_and_replace(string& text, const string& search, const string& replace)
{
	size_t pos = 0;
	while ((pos = text.find(search, pos)) != std::string::npos) 
	{
		text.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

int main()
{
	string text;
	string search;
	string replace;

	cout << "Write text content: ";
	getline(cin, text);
	cout << "Write what you want to find in content: ";
	getline(cin, search);
	cout << "Write with what you want to replace it: ";
	getline(cin, replace);
	find_and_replace(text,search, replace);
	cout << text << endl;

	return 0;
}