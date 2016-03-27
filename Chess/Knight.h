#pragma once

#include "Piece.h"
#include "Board.h"

 class Knight : public Piece
{
public:
	Knight(Coordinate);

	void setIsWhite(const bool) override;

protected:
	std::vector<Coordinate> computeMoves() override;

	//experimental
	Board board = Board::getInstance();

private:
	void addMove(const Coordinate&);



};

