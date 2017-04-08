#include "Bishop.h"

Bishop::Bishop(char symbol, Color color, Position pos) :
	Figure(symbol, color, pos)
{
}

Figure * Bishop::getAvailableMoves(const Figure * otherFigures)
{
	return nullptr;
}

bool Bishop::move(Position & newPosition, Position * otherFigures)
{
	return false;
}

Bishop::~Bishop()
{
}

