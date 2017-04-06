#include <string>
#include <iostream>
#include <queue> 
using namespace std;

bool check_unclosed_tag(string str)
{
	std::queue<int> bracket_queue;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			bracket_queue.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (bracket_queue.empty())
			{
				return false;
			}

			bracket_queue.pop();
		}

	}

	if (bracket_queue.empty())
	{
		return true;
	}

	return false;
}

int main()
{
	string input_line;
	getline(cin ,input_line);

	if (check_unclosed_tag(input_line))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}