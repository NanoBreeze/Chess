#include "WhitePlayer.h"


WhitePlayer::WhitePlayer() 
{

	//initialize white player's pieces
	pawn1 = new Pawn(Coordinate::A2);
	pawn2 = new Pawn(Coordinate::B2);
	pawn3 = new Pawn(Coordinate::C2);
	pawn4 = new Pawn(Coordinate::D2);
	pawn5 = new Pawn(Coordinate::E2);
	pawn6 = new Pawn(Coordinate::F2);
	pawn7 = new Pawn(Coordinate::G2);
	pawn8 = new Pawn(Coordinate::H2);

	rook1 = new Rook(Coordinate::A1);
	knight1 = new Knight(Coordinate::B1);
	bishopBlack = new Bishop(Coordinate::C1);
	queen = new Queen(Coordinate::D1);
	king = new King(Coordinate::E1);
	bishopWhite = new Bishop(Coordinate::F1);
	knight2 = new Knight(Coordinate::G1);
	rook2 = new Rook(Coordinate::H1);
}
