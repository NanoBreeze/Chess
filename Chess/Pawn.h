#pragma once


#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(Coordinate coordinate);
	void setCoordinate(const Coordinate position) override;


protected :
	void computeMoves() override;

	//experimental
	Board board = Board::Instance();

private:
	//this determines if the pawn can move to pieces or only one
	bool hasYetToMove;

	void addCaptureMove(const Coordinate&);
};

