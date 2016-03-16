#include "Board.h"


//board creates the squares
Board::Board()
{
	//use for loop instead of iterator because the loop count corresponds to a coordinate	
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			//consider making a map for Coordinate and default colour, requires refactoring, difficult to read, magic numbers, etc.

			Coordinate coordinate = static_cast<Coordinate>(8 * row + column);

			Board::squares[column][row].setCoordinateAndDefaultColour(coordinate);
			Board::squares[column][row].setPosition(sf::Vector2f(column * 50, 350 - row * 50));
		}
	}
}

Square& Board::operator[](const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	return squares[column][row];
}

Board& Board::getInstance()
{
	static Board board;
	return board;
}

void Board::highlightLegalSquares(const std::vector<Coordinate> moves)
{
	//empty moves won't result in any operation
	for (auto coordinate : moves)
	{
		int row = (int)coordinate / 8;
		int column = (int)coordinate % 8;

		squares[column][row].showLegalMoveColour();
	}
}

void Board::addPiecesToSquares(std::vector<Piece*> pieces)
{
	for (auto piece : pieces)
	{
		auto coordinate = piece->getCoordinate();

		int row = (int)coordinate / 8;
		int column = (int)coordinate % 8;

		squares[column][row].setPiece(piece);
	}
}

Square Board::squares[8][8];





