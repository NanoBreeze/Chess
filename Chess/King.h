#pragma once

#include "Piece.h"
//#include "Board.h"
#include "Board.h"

class King : public Piece
{
public:
	King(Coordinate coordinate);

	void setIsWhite(const bool) override;

protected:
	std::vector<Coordinate> computeMoves() override;

	//experimental
	Board board = Board::getInstance();

private:
	//helps out computeMoves
	void addMove(const Coordinate&);
};

