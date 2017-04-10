#pragma once
enum Color
{
	WHITE,
	BLACK
};

class Position
{
private:
	char x;
	int y;
public:
	Position() : x(0), y(0){}
	Position(char x, int y) : x(x), y(y)	{}
	int getX() const { return this->x; }
	int getY() const { return this->x; }
	void setX(const char& x) { this->x = x; }
	void setY(const int& y) { this->y = y; }
};

class Figure
{
protected:
	char symbol;
	Color color;
	Position pos;
public:

	Figure(char symbol, Color color, Position pos);
	~Figure();

	std::string get();
	//std::string getAvailableMoves();
   //  bool move(Position newPosition, Position ** otherFigures);
};

