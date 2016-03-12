#pragma once

#include "Board.h"

class Helper
{
public:
	Helper();

	//temporarily in the Helper class. This returns the Square associated with the row and column
	static Square* getSquare(int row, int column) { return &Board::squares[column][row]; }
};

