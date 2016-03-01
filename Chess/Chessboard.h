#pragma once

#include "Square.h"

//contains 64 Squares to represent a chessboard
class Chessboard
{
public:
	//sets up the board
	Chessboard();

	//SHOULD BE PRIVATE array of the squares on a chessboard
	Square squares[8][8];

private:
};

