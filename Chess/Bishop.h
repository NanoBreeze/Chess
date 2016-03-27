#pragma once

#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{
public:
	Bishop(Coordinate coordinate);

	void setIsWhite(const bool) override;


protected : 

	//called every time the bishop moves to a new square or is newly made because that's when its movable squares change.
	std::vector<Coordinate> computeMoves() override;

	//experimental
	Board board = Board::getInstance();
private:
	//helps with computeMoves
	bool addPartOne(const Coordinate&);
};


