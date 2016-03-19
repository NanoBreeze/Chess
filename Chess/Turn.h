#pragma once

//Includes info for each turn (meant to be placed onto the turn stack). Info includes:
//Piece moved 
//from and to coordinate
//Piece captured (if any)

#include "Piece.h"
#include "Coordinate.h"

class Turn
{
public:
	Turn();
	~Turn();

	Piece* getPieceMoved() const;
	void setPieceMoved(Piece*);

	Coordinate getFromCoordinate() const;
	void setFromCoordinate(Coordinate);

	Coordinate getToCoordinate() const;
	void setToCoordinate(Coordinate);

	Piece* getCapturedPiece() const;
	void setCapturedPiece(Piece*);

private:
	//The piece that just moved
	Piece* pieceMoved = nullptr;
	
	//the Coordinate of pieceMoved before it moved
	Coordinate fromCoordinate;
	
	//the Coordinate of pieceMoved after it moved
	Coordinate toCoordinate;

	//the Piece that the pieceMoved captured (aka, occupied toCoordinate before pieceMoved moved
	Piece* capturedPiece = nullptr;

};

