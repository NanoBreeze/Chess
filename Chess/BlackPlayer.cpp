#include "BlackPlayer.h"



BlackPlayer::BlackPlayer()
{
	//initialize black player's pieces, pawn1 is the black player's left-most pawn
	pawn1 = new Pawn(Coordinate::H7);
	pawn1->setIsWhite(false);

	pawn2 = new Pawn(Coordinate::G7);
	pawn2->setIsWhite(false);

	pawn3 = new Pawn(Coordinate::F7);
	pawn3->setIsWhite(false);

	pawn4 = new Pawn(Coordinate::E7);
	pawn4->setIsWhite(false);

	pawn5 = new Pawn(Coordinate::D7);
	pawn5->setIsWhite(false);

	pawn6 = new Pawn(Coordinate::C7);
	pawn6->setIsWhite(false);

	pawn7 = new Pawn(Coordinate::B7);
	pawn7->setIsWhite(false);

	pawn8 = new Pawn(Coordinate::A7);
	pawn8->setIsWhite(false);

	rook1 = new Rook(Coordinate::H8);
	rook1->setIsWhite(false);

	knight1 = new Knight(Coordinate::G8);
	knight1->setIsWhite(false);

	bishopBlack = new Bishop(Coordinate::F8);
	bishopBlack->setIsWhite(false);

	king = new King(Coordinate::E8);
	king->setIsWhite(false);

	queen = new Queen(Coordinate::D8);
	queen->setIsWhite(false);

	bishopWhite = new Bishop(Coordinate::C8);
	bishopWhite->setIsWhite(false);

	knight2 = new Knight(Coordinate::B8);
	knight2->setIsWhite(false);

	rook2 = new Rook(Coordinate::A8);
	rook2->setIsWhite(false);



}
