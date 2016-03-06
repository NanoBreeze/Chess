#include "Piece.h"



Piece::Piece()
{
}

Position Piece::getPosition() const
{
	return position;
}

Coordinate Piece::getCoordinate() const
{
	return coordinate;
}

void Piece::setCoordinate(Coordinate coordinate)
{
	this->coordinate = coordinate;

	//gets row and column
	int row = getRow();
	int column = getColumn();

	//sets the position, use helper method instead and take out magic numbers
	setPosition(sf::Vector2f(column * 50, 350 - row * 50));
	computeMovableSquares();
}

std::vector<Coordinate> Piece::getMovableSquares() const
{
	return movableSquares;
}

int Piece::getRow() const
{
	return (int)coordinate / 8;
}

int Piece::getColumn() const
{
	return (int)coordinate % 8;
}

Coordinate Piece::computeCoordinate(int row, int column)
{
	return static_cast<Coordinate> (row * 8 + column);
}