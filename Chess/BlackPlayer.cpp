#include "BlackPlayer.h"



BlackPlayer::BlackPlayer()
{
	//initialize black player's pieces, pawn1 is the black player's left-most pawn
	pawn1 = new Pawn(Coordinate::H7);
	pawn1->setIsWhite(false);
	pieces.push_back(pawn1);

	pawn2 = new Pawn(Coordinate::G7);
	pawn2->setIsWhite(false);
	pieces.push_back(pawn2);

	pawn3 = new Pawn(Coordinate::F7);
	pawn3->setIsWhite(false);
	pieces.push_back(pawn3);

	pawn4 = new Pawn(Coordinate::E7);
	pawn4->setIsWhite(false);
	pieces.push_back(pawn4);

	pawn5 = new Pawn(Coordinate::D7);
	pawn5->setIsWhite(false);
	pieces.push_back(pawn5);

	pawn6 = new Pawn(Coordinate::C7);
	pawn6->setIsWhite(false);
	pieces.push_back(pawn6);

	pawn7 = new Pawn(Coordinate::B7);
	pawn7->setIsWhite(false);
	pieces.push_back(pawn7);

	pawn8 = new Pawn(Coordinate::A7);
	pawn8->setIsWhite(false);
	pieces.push_back(pawn8);

	rook1 = new Rook(Coordinate::H8);
	rook1->setIsWhite(false);
	pieces.push_back(rook1);

	knight1 = new Knight(Coordinate::G8);
	knight1->setIsWhite(false);
	pieces.push_back(knight1);

	bishopBlack = new Bishop(Coordinate::F8);
	bishopBlack->setIsWhite(false);
	pieces.push_back(bishopBlack);

	king = new King(Coordinate::E8);
	king->setIsWhite(false);
	pieces.push_back(king);

	queen = new Queen(Coordinate::D8);
	queen->setIsWhite(false);
	pieces.push_back(queen);

	bishopWhite = new Bishop(Coordinate::C8);
	bishopWhite->setIsWhite(false);
	pieces.push_back(bishopWhite);

	knight2 = new Knight(Coordinate::B8);
	knight2->setIsWhite(false);
	pieces.push_back(knight2);

	rook2 = new Rook(Coordinate::A8);
	rook2->setIsWhite(false);
	pieces.push_back(rook2);

	

}
