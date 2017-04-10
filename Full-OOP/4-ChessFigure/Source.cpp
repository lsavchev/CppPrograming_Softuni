#include <iostream>
#include "Figure.h"
#include "Bishop.h"
#include "Queen.h"
int main()
{
	Figure ** bit;
	
	//bit[0] = new Bishop('b', WHITE, Position(1, 1));
	//bit[1] = new Bishop('b', WHITE, Position(1, 1));
	Bishop b('b', WHITE, Position(1, 1));
	Position p;
	std::vector<Position> pos;
	//pos = b.getAvailableMoves(bit);
	return 0;
}