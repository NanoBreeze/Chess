#pragma once


#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(Coordinate coordinate);
	void setCoordinate(const Coordinate position) override;


protected :
	std::vector<Coordinate> computeMoves() override;

	//experimental
	Board board = Board::getInstance();

private:
	//this determines if the pawn can move to pieces or only one
	bool hasYetToMove;

	void addCaptureMove(const Coordinate&);
};

