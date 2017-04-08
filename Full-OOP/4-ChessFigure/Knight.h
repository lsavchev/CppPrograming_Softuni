#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight(char symbol, Color color, Position pos);
	~Knight();
};

