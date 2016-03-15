#include "Board.h"



Board::Board()
{

}

//Square& Board::getSquare(const Coordinate& coordinate)
//{
//	int row = (int)coordinate / 8;
//	int column = (int)coordinate % 8;
//
//	return squares[column][row];
//
//}

Square& Board::operator[](const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	return squares[column][row];
}

Board& Board::Instance()
{
	static Board board;
	return board;
}

Square Board::squares[8][8];




 