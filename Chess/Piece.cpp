#include "Piece.h"




Piece::Piece()
{
}

Piece::Piece(Coordinate coordinate)
{
	
}

Position Piece::getPosition() const
{
	return position;
}

void Piece::setPosition(const Coordinate coordinate)
{
	position.setPosition(coordinate);

	int column = position.getColumn();
	int row = position.getRow();

	//sets the position, use helper method instead and take out magic numbers
	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));
	computeMovablePositions();
}

void Piece::setPosition(const Position position)
{
	this->position = position;

	int column = position.getColumn();
	int row = position.getRow();

	//sets the position, use helper method instead and take out magic numbers
	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));
	computeMovablePositions();
}

std::vector<Position> Piece::getMovablePositions() const
{
	return movablePositions;
}


Position Piece::computePosition(int row, int column)
{
	Position p;
	p.setPosition(row, column);

	return p;
}

