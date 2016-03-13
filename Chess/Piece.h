#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Position.h"
//#include "Board.h"


class Piece : public sf::RectangleShape
{
public:

	Piece();

	//sets the piece's Position given its Coordinate
	Piece(Coordinate);

	Position getPositionWithPosition() const;

	//sets the piece to the specified coordinate, along with its row-column position, along with the squares it can move to
	 void setPosition(const Coordinate coordinate);

	 //same as above but accepts a Position object instead. Used when a Square sets the Position of a Piece associated to it.
	 //add virtual only for pawn to change status of if the pawn has already moved
	 virtual void setPosition(const Position position);

	//returns the vector of Coordinates this piece is eligeble to move to
	std::vector<Position> getMovablePositions() const;

	//clears all elements in movablePositions. Used when we change a Piece's position
	void clearMovablePositions();

	//calculates the eligible Squares this piece can move to, its getter is getMovableSquares()
	virtual void computeMovablePositions() = 0;

	//gets isWhite to return if Piece belongs to white or black player
	bool getIsWhite() const;

	void setIsWhite(const bool);

protected: 

	//determines if the Piece is belongs to white or black player
	bool isWhite;

	//contains this piece's Coordinate, row and column
	Position position;

	//contains the coordinates this piece is eligible to move to. This field frequently changes
	//std::vector<Coordinate> movableSquares;

	//contains the Positions (Coordinate, row, column) this piece is eligible to move to. This field frequently changes
	std::vector<Position> movablePositions;



	Position computePosition(int row, int column);
};

