#include "Piece.h"



Piece::Piece()
{
}

Position Piece::getPosition() const
{
	return position;
}

void Piece::setCoordinate(const Coordinate coordinate)
{
	position.setPosition(coordinate);

	int column = position.getColumn();
	int row = position.getRow();

	//sets the position, use helper method instead and take out magic numbers
	setPosition(sf::Vector2f(column * 50, 350 - row * 50));
	computeMovableSquares();
}

std::vector<Coordinate> Piece::getMovableSquares() const
{
	return movableSquares;
}

Coordinate Piece::computeCoordinate(int row, int column)
{
	return static_cast<Coordinate> (row * 8 + column);
}

