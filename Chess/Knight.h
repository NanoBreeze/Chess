#pragma once

#include "Piece.h"

 class Knight : public Piece
{
public:
	Knight(Coordinate);

protected:
	void computeMovablePositions() override;
};

