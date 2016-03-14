#include "Board.h"



Board::Board()
{
}

Square& Board::getSquare(Coordinate coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	return squares[column][row];

}

Square Board::squares[8][8];



 