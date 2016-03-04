#pragma once

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include <vector>

class Piece : public sf::RectangleShape
{
public:
	Piece();

	//returns the coordinates associated with the piece
	 Coordinate getCoordinate() const;

	//sets the piece to the specified coordinate, along with its row-column position, along with the squares it can move to
	 void setCoordinate(Coordinate coordinate);

	//returns the vector of Coordinates this piece is eligeble to move to
	std::vector<Coordinate> getMovableSquares() const;

protected: 

	//the coordinates of this piece, its "properties" are getCoordinate() and setCoordinate()
	Coordinate coordinate;

	//contains the coordinates this piece is eligible to move to. This field frequently changes
	std::vector<Coordinate> movableSquares;

	//calculates the eligible Squares this piece can move to, its getter is getMovableSquares()
	virtual void computeMovableSquares() = 0;

	//returns this piece's row from its coordinate
	int getRow() const;

	//returns this piece's column from its coordinate
	int getColumn() const;

	//computes the coordinate from the row and column
	Coordinate computeCoordinate(int row, int column);

};

