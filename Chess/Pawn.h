#pragma once


#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Coordinate coordinate);
	void setPosition(const Position position) override;


protected :
	void computeMovablePositions() override;

private:
	//this determines if the pawn can move to pieces or only one
	bool hasYetToMove;
};

