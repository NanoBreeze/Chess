#include "Position.h"


//we assign row and column both to -1 to demonstrate that they dont' have valid values to start with
Position::Position() : row(-1), column(-1)
{
}

void Position::setPosition(const Coordinate coordinate)
{
	this->coordinate = coordinate;

	//sets the piece's row and column from its Coordinate
	setRow(coordinate);
	setColumn(coordinate);
}

void Position::setPosition(const int row, const int column)
{
	this->row = row;
	this-> column = column;

	//sets the piece's Coordinate from its row and column
	setCoordinate(row, column);
	
}

Coordinate Position::getCoordinate() const
{
	return coordinate;
}


int Position::getRow() const
{
	return row;
}


int Position::getColumn() const
{
	return column;
}





void Position::setRow(const Coordinate coordinate)
{
	row = (int)coordinate / 8;
}

void Position::setColumn(const Coordinate coordinate)
{
	column = (int)coordinate % 8;
}

void Position::setCoordinate(const int row, const int column)
{
	coordinate = static_cast<Coordinate> (row * 8 + column);
}

