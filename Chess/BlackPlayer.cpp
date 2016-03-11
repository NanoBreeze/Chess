#include "BlackPlayer.h"



BlackPlayer::BlackPlayer()
{
	//initialize black player's pieces, pawn1 is the black player's left-most pawn
	pawn1 = new Pawn(Coordinate::H7);
	pawn2 = new Pawn(Coordinate::G7);
	pawn3 = new Pawn(Coordinate::F7);
	pawn4 = new Pawn(Coordinate::E7);
	pawn5 = new Pawn(Coordinate::D7);
	pawn6 = new Pawn(Coordinate::C7);
	pawn7 = new Pawn(Coordinate::B7);
	pawn8 = new Pawn(Coordinate::A7);

	rook1 = new Rook(Coordinate::H8);
	knight1 = new Knight(Coordinate::G8);
	bishopBlack = new Bishop(Coordinate::F8);
	king = new King(Coordinate::E8);
	queen = new Queen(Coordinate::D8);
	bishopWhite = new Bishop(Coordinate::C8);
	knight2 = new Knight(Coordinate::B8);
	rook2 = new Rook(Coordinate::A8);
}
