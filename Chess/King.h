#pragma once

#include "Piece.h"
//#include "Board.h"
#include "Board.h"

class King : public Piece
{
public:
	King(Coordinate coordinate);

protected: 
	void computeMoves() override;

	//experimental
	Board board;

private:
	//helps out computeMoves
	void addMove(const Coordinate&);
};

