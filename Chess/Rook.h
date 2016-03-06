#pragma once

#include "Piece.h"

 class Rook : public Piece
{
public:
	Rook();

protected:

	//called every time the bishop moves to a new square or is newly made because that's when its movable squares change.
	//movable squares include all verticals and horizontals
	void computeMovablePositions() override;
};

