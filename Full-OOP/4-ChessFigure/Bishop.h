#pragma once
#include "Figure.h"
#include <vector>
class Bishop :
	public Figure
{
public:
	Bishop(char symbol, Color color, Position pos);
	Bishop::~Bishop();

	char GetSybol() { return this->symbol; }
	

};

