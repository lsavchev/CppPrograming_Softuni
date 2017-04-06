#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

int calculateMatches(string str1, string str2)
{
	if (str1.size() != str2.size())
	{
		return 0;
	}
	if (str1[0] != str2[0])
	{
		return 0;
	}
	int matches = 1;
	for (size_t i = 1; i < str1.size(); i++)
	{
		if (str1[i] == str2[i])
		{
			matches++;
		}
	}

	return matches;
}

int main()
{
	string firstLineInput;
	string secondLineInput;
	string W2;
	string single_word;
	int P;
	vector<string> words;
	getline(cin, firstLineInput);
	getline(cin, secondLineInput);
	stringstream stream(secondLineInput);
	stream >> single_word >> P;
	int start_index_word = 0;
	for (size_t i = 0; i < firstLineInput.size(); i++)
	{
		if (ispunct(firstLineInput[i]) || isspace(firstLineInput[i]))
		{
			string word = firstLineInput.substr(start_index_word, i - start_index_word);
			words.push_back(word);
			start_index_word = i+1;
		}
		else if (i == firstLineInput.size() - 1)
		{
			i++;
			string word = firstLineInput.substr(start_index_word, i - start_index_word);
			words.push_back(word);
			start_index_word = i;
		}
	}
	int match = 0;
	int coutResult = 0;
	for (size_t i = 0; i < words.size(); i++)
	{		
		match = calculateMatches(single_word, words[i]);
		double percentMatch = ((double)match / (double)single_word.size()) * (double)100;
		if ((double)P <= percentMatch)
		{
			coutResult++;
		}
	}
	cout << coutResult << endl;
	return 0;
}