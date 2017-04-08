#include "Queen.h"


Queen::Queen(char symbol, Color color, Position pos) :
	Figure(symbol, color, pos)
{
}

Queen::~Queen()
{
}

Figure * Queen::getAvailableMoves(const Figure * otherFigures)
{
	return nullptr;
}

bool Queen::move(Position & newPosition, Position * otherFigures)
{
	return false;
}
