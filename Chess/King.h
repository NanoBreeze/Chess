#pragma once

#include "Piece.h"
//#include "Board.h"

class King : public Piece
{
public:
	King(Coordinate coordinate);

protected: 
	void computeMoves() override;

private:
	//helps out computeMoves
	void addMove(const Coordinate&);
};

