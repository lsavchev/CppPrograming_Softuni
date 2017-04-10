#pragma once
#include "Figure.h"
class Queen :
	public Figure
{
public:
	Queen(char symbol, Color color, Position pos);
	~Queen();

};

