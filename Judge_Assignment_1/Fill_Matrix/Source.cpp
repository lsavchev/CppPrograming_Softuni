#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

struct cordinatesMatrix
{
	int x;
	int y;
	char value;
};


void recursivecall(int *max[],char ch, int rowsize, int colsize , int currentRow, int currentCol)
{
	int keepPathX = currentRow;
	int keepPathY = currentCol;

	if (currentRow <= (rowsize - 1) || currentRow >= 0 || currentCol <= (colsize - 1) || currentCol >= 0)
	{
		if (max[currentRow][currentCol] == ch)
		{
			max[currentRow][currentCol] = ch;
		}
	}
	
}

int main()
{
	int row;
	int col;
	string row_cow_input;
	string matricInput;

	getline(cin, row_cow_input);
	stringstream ss(row_cow_input);
	ss >> row >> col;
	string charsInline;
	char ** matrix = new char*[row];
	for (int i = 0; i < row; ++i)
		matrix[i] = new char[col];

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}

	char character;
	cin >> character;

	int StartRow;
	int StartCol;
	cin >> StartRow;
	cin >> StartCol;

	char equalChar = matrix[StartRow][StartCol];
	char currentChar = matrix[StartRow][StartCol];
	matrix[StartRow][StartCol] == character;

	for (size_t i = StartRow; i < row; i++)
	{
		for (size_t i = StartCol; i < col; i++)
		{
			
		} 
	}

	for (size_t i = StartRow; i >= row; i--)
	{
		for (size_t i = StartCol; i >= col; i--)
		{

		}
	}

	return 0;
}