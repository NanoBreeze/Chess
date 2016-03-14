#pragma once


#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Coordinate coordinate);
	void setCoordinate(const Coordinate position) override;


protected :
	void computeMoves() override;

private:
	//this determines if the pawn can move to pieces or only one
	bool hasYetToMove;

	void addCaptureMove(const Coordinate&);
};

