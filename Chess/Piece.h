#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Coordinate.h"
#include "CoordinateHelper.h"
//#include "Position.h"
//#include "Board.h"


class Piece : public sf::RectangleShape
{
public:

	Piece();

	//sets the piece's Position given its Coordinate
	Piece(Coordinate);

	//========================== THIS WILL BE REPLACED WITH getCoordinate() const;
	//Position getPositionWithPosition() const;

	//returns the coordinate this piece has
	Coordinate getCoordinate() const;

	//=========================== THIS IS REPLACED BY setCoordinate sets the piece to the specified coordinate, along with its row-column position, along with the squares it can move to
	 //void setPosition(const Coordinate coordinate);

	 //same as above but accepts a Position object instead. Used when a Square sets the Position of a Piece associated to it.
	 //add virtual only for pawn to change status of if the pawn has already moved
	 //virtual void setPosition(const Position position);

	 //sets coordinate to the given Coordinate. Denotes that this piece on the coordinate
	 virtual void setCoordinate(const Coordinate);



	//============================ THIS IS REPLACED BY getMoves() returns the vector of Coordinates this piece is eligeble to move to
	//std::vector<Position> getMovablePositions() const;

	 //returns moves, 
	 std::vector<Coordinate> getMoves() const;

	//============================ THIS IS REPLACED BY clearMoves() clears all elements in movablePositions. Used when we change a Piece's position
	//void clearMovablePositions();

	//clears all COordinates in moves
	void clearMoves();

	//calculates the eligible Squares this piece can move to, its getter is getMovableSquares()
	virtual void computeMoves() = 0;

	//gets isWhite to return if Piece belongs to white or black player
	bool getIsWhite() const;

	void setIsWhite(const bool);

protected: 

	//determines if the Piece is belongs to white or black player
	bool isWhite;

	//=================== THIS IS REPLACED WITH coordinate contains this piece's Coordinate, row and column
	/*Position position;*/

	//replaces Position
	Coordinate coordinate;



	//=================== THIS IS REPLACED BY moves contains the coordinates this piece is eligible to move to. This field frequently changes
	//std::vector<Coordinate> movableSquares;


	//================== THIS IS REPLACED BY moves contains the Positions (Coordinate, row, column) this piece is eligible to move to. This field frequently changes
	//std::vector<Position> movablePositions;

	//stores the Coordinates of the places this piece can move to
	std::vector<Coordinate> moves;

	
	//Position computePosition(int row, int column);

	
};

