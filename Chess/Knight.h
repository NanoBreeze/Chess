#pragma once

#include "Piece.h"

 class Knight : public Piece
{
public:
	Knight(Coordinate);

protected:
	void computeMoves() override;

private:
	void addMove(const Coordinate&);



};

