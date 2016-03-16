#pragma once

#include "Square.h"
#include "Coordinate.h"
#include <vector>
#include "Piece.h"

 class Board
{
public:

	//singleton for the Board
	static Board& getInstance();

	//Squares are used with board[Coordinate::A1] instead of squares[column][row], which is for internal use only
	Square& operator[](const Coordinate&);

	//receives Coordinates. Highlights the Squares that contain these matching Coordinates
	void highlightLegalSquares(const std::vector<Coordinate> movableCoordinates);

	//Each Piece contains a coordinate, and we set the Piece reference on the Square whose row/column matches the Piece's Coordinate
	void addPiecesToSquares(std::vector<Piece*>) ;

private:

	//Representation of the board in real life
	static Square squares[8][8];

	Board();

 };



