#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King(char symbol, Color color, Position pos);
	~King();
};

