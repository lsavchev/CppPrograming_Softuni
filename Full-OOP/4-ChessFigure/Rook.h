#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook(char symbol, Color color, Position pos);
	~Rook();
};

