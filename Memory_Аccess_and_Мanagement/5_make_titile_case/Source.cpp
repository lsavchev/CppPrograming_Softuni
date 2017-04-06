#include <string>
#include <iostream>

using namespace std;

void makeTitleCase(string& text)
{
	bool was_space = true; 
	int counter = 0;

	for (size_t i = counter; i < text.size(); i++)
	{		
		if (text[i] == ' ')
		{
			was_space = true;
		}
		else
		{
			if (was_space)
			{
				text[i] -= 0x20; //assume everything else is correct, i.e. you don’t need to check for correct signs, correct variables/numbers, etc.)
									// оп условие не трябват проверки за range.			
				was_space = false;
			}
		}
	}
}

int main()
{
	string input;
	getline(cin, input);
	makeTitleCase(input);
	cout << input << endl;

	return 0;
}