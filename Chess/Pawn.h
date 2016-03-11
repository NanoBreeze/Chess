#pragma once


#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Coordinate coordinate);

protected :
	void computeMovablePositions() override;
};

