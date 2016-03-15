#pragma once

#include "Square.h"
#include "Coordinate.h"

 class Board
{
public:
	Board();


	//returns the Square associated with the Coordinate
	//static Square& getSquare(const Coordinate&);

	Square& operator[](const Coordinate&);
	//singleton for the Board
	static Board& Instance();

private:
	static Square squares[8][8];

 };



