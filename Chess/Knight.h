#pragma once

#include "Piece.h"
#include "Board.h"

 class Knight : public Piece
{
public:
	Knight(Coordinate);

protected:
	void computeMoves() override;

	//experimental
	Board board;

private:
	void addMove(const Coordinate&);



};

