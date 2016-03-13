#include "WhitePlayer.h"


WhitePlayer::WhitePlayer() 
{

	//initialize white player's pieces
	pawn1 = new Pawn(Coordinate::A2);
	pawn1->setIsWhite(true);

	pawn2 = new Pawn(Coordinate::B2);
	pawn2->setIsWhite(true);

	pawn3 = new Pawn(Coordinate::C2);
	pawn3->setIsWhite(true);

	pawn4 = new Pawn(Coordinate::D2);
	pawn4->setIsWhite(true);

	pawn5 = new Pawn(Coordinate::E2);
	pawn5->setIsWhite(true);

	pawn6 = new Pawn(Coordinate::F2);
	pawn6->setIsWhite(true);

	pawn7 = new Pawn(Coordinate::G2);
	pawn7->setIsWhite(true);

	pawn8 = new Pawn(Coordinate::H2);
	pawn8->setIsWhite(true);

	rook1 = new Rook(Coordinate::A1);
	rook1->setIsWhite(true);

	knight1 = new Knight(Coordinate::B1);
	knight1->setIsWhite(true);

	bishopBlack = new Bishop(Coordinate::C1);
	bishopBlack->setIsWhite(true);

	queen = new Queen(Coordinate::D1);
	queen->setIsWhite(true);

	king = new King(Coordinate::E1);
	king->setIsWhite(true);

	bishopWhite = new Bishop(Coordinate::F1);
	bishopWhite->setIsWhite(true);

	knight2 = new Knight(Coordinate::G1);
	knight2->setIsWhite(true);

	rook2 = new Rook(Coordinate::H1);
	rook2->setIsWhite(true);
}
