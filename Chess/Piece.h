#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"

class Piece : public sf::RectangleShape
{
public:
	Piece();

	Position getPosition() const;

	//sets the piece to the specified coordinate, along with its row-column position, along with the squares it can move to
	 void setPosition(const Coordinate coordinate);

	 //same as above but accepts a Position object instead. Used when a Square sets the Position of a Piece associated to it.
	 void setPosition(const Position position);

	//returns the vector of Coordinates this piece is eligeble to move to
	std::vector<Position> getMovablePositions() const;

protected: 

	//contains this piece's Coordinate, row and column
	Position position;

	//contains the coordinates this piece is eligible to move to. This field frequently changes
	//std::vector<Coordinate> movableSquares;

	//contains the Positions (Coordinate, row, column) this piece is eligible to move to. This field frequently changes
	std::vector<Position> movablePositions;

	//calculates the eligible Squares this piece can move to, its getter is getMovableSquares()
	virtual void computeMovablePositions() = 0;

	Position computePosition(int row, int column);
};

