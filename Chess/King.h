#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(Coordinate coordinate);

protected: 
	void computeMovablePositions() override;
};

