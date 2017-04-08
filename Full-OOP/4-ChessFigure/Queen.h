#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(char symbol, Color color, Position pos);
	~Queen();

	// Inherited via Figure
	virtual Figure * getAvailableMoves(const Figure * otherFigures) override;
	virtual bool move(Position & newPosition, Position * otherFigures) override;
};

