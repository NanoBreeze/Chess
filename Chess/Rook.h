#pragma once

#include "Piece.h"
#include "Board.h"

 class Rook : public Piece
{
public:
	Rook(Coordinate coordinate) ;

protected:

	//called every time the bishop moves to a new square or is newly made because that's when its movable squares change.
	//movable squares include all verticals and horizontals
	void computeMoves() override;

	//experimental
	Board board;

private:
	//helps with computeMoves
	bool addPartOne(const Coordinate&);
};

