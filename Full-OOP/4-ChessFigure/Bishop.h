#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop(char symbol, Color color, Position pos);
	Bishop::~Bishop();
	// Inherited via Figure
	virtual Figure * getAvailableMoves(const Figure * otherFigures) override;

	virtual bool move(Position & newPosition, Position * otherFigures) override;

};

