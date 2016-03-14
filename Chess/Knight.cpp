#include "Knight.h"
#include "Board.h"


Knight::Knight(Coordinate coordinate)
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	setSize(sf::Vector2f(20, 20));
}

void Knight::computeMoves()
{
	//can optimize

	//first clear past movablePositions
	clearMoves();



	//2 up 1 left
	if (CoordinateHelper::TwoUpOneLeft(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::TwoUpOneLeft(coordinate));
	}
	
	//2 up 1 right
	if (CoordinateHelper::TwoUpOneRight(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::TwoUpOneRight(coordinate));
	}


	//1 up 2 left
	if (CoordinateHelper::OneUpTwoLeft(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::OneUpTwoLeft(coordinate));
	}

	//1 up 2 right
	if (CoordinateHelper::OneUpTwoRight(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::OneUpTwoRight(coordinate));
	}

	//1 down 2 left
	if (CoordinateHelper::OneDownTwoLeft(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::OneDownTwoLeft(coordinate));
	}

	//1 down 2 right
	if (CoordinateHelper::OneDownTwoRight(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::OneDownTwoRight(coordinate));
	}

	//2 down 1 left
	if (CoordinateHelper::TwoDownOneLeft(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::TwoDownOneLeft(coordinate));
	}

	//2 down 1 right
	if (CoordinateHelper::TwoDownOneRight(coordinate) != Coordinate::Invalid)
	{
		addMove(CoordinateHelper::TwoDownOneRight(coordinate));
	}
}

void Knight::addMove(const Coordinate& coor)
{
	//1
	if (Board::getSquare(coor).getPiece() != nullptr)
	{
		//a)
		if (Board::getSquare(coor).getPiece()->getIsWhite() == this->isWhite)
		{
			//that square is not placed into movablePositions
		}
		//b)
		else
		{
			moves.push_back(coor);

		}
	}
	else
	{
		moves.push_back(coor);
	}
}


