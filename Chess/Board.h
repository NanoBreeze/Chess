#pragma once

#include "Square.h"
#include "Coordinate.h"

 class Board
{
public:
	Board();

	static Square squares[8][8];

	//returns the Square associated with the Coordinate
	static Square& getSquare(Coordinate);

private:

 };

