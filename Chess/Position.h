#pragma once

#include "Coordinate.h"

//part of Piece, denotes the piece's position on the board by storing its Coordinate, row, and column
 class Position
{
public:
	Position();

	//sets the piece's Coordinate, and automatically uses that to deduce the piece's row and column
	void setPosition(const Coordinate coordinate);

	//sets the piece's row and colum, and automatically uses that do deduce the piece's Coordinate
	void setPosition(const int row, const int column);

	//gets the row, column, and coordinate this piece is in. If any of the given are set, then all are set.
	int getRow() const;
	int getColumn() const;
	Coordinate getCoordinate() const;

private:

	//consider having a setRow and setColumn accepting int

	//sets the piece's row from its Coordinate, called by setPosition(const Coordinate coordinate)
	void setRow(const Coordinate coordinate);

	//sets the piece's column from its Coordinate, called by setPosition(const Coordinate coordinate)
	void setColumn(const Coordinate coordinate);

	//sets the piece's Coordinate from its row and column, called by setPosition(const int row, const int column)
	void setCoordinate(const int row, const int column);

	//the coordinate this piece is on
	Coordinate coordinate;

	//the row this piece is on, eg, 1st row, 3rd row
	int row;

	//the column this piece is on
	int column;
};

