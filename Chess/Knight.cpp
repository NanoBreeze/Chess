#include "Knight.h"
#include "Board.h"


Knight::Knight(Coordinate coordinate)
{
	symbol = "N";
	this->coordinate = coordinate;
	texture.loadFromFile("WhiteKnight.png");
	setTexture(texture);


	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	setPosition(sf::Vector2f(column * 50, 350 - row * 50));

}

void Knight::setIsWhite(const bool isWhite)
{
	this->isWhite = isWhite;

	if (isWhite)
	{
		texture.loadFromFile("WhiteKnight.png");
	}
	else
	{
		texture.loadFromFile("BlackKnight.png");
	}
	setTexture(texture);

}

std::vector<Coordinate> Knight::computeMoves()
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

	return moves;
}

void Knight::addMove(const Coordinate& coor)
{
	//1
	if (board[coor].getPiece() != nullptr)
	{
		//a)
		if (board[coor].getPiece()->getIsWhite() == this->isWhite)
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


