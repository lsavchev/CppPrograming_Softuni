#pragma once
#include "Figure.h"
class Pawn :
	public Figure
{
public:
	Pawn(char symbol, Color color, Position pos);
	~Pawn();
};

