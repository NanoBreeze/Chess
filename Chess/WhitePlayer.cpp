#include "WhitePlayer.h"
#include <iostream>

WhitePlayer::WhitePlayer() 
{

	//initialize white player's pieces

	std::cout << "About to make first white pawn";

	pawn1 = new Pawn(Coordinate::A2);
	pawn1->setIsWhite(true);
	pieces.push_back(pawn1);

	pawn2 = new Pawn(Coordinate::B2);
	pawn2->setIsWhite(true);
	pieces.push_back(pawn2);

	pawn3 = new Pawn(Coordinate::C2);
	pawn3->setIsWhite(true);
	pieces.push_back(pawn3);

	pawn4 = new Pawn(Coordinate::D2);
	pawn4->setIsWhite(true);
	pieces.push_back(pawn4);

	pawn5 = new Pawn(Coordinate::E2);
	pawn5->setIsWhite(true);
	pieces.push_back(pawn5);

	pawn6 = new Pawn(Coordinate::F2);
	pawn6->setIsWhite(true);
	pieces.push_back(pawn6);

	pawn7 = new Pawn(Coordinate::G2);
	pawn7->setIsWhite(true);
	pieces.push_back(pawn7);

	pawn8 = new Pawn(Coordinate::H2);
	pawn8->setIsWhite(true);
	pieces.push_back(pawn8);

	std::cout << "Finished making last white pawn";

	std::cout << "About to make first rook\n";
	rook1 = new Rook(Coordinate::A1);
	rook1->setIsWhite(true);
	pieces.push_back(rook1);

	std::cout << "About to make first knight\n";

	knight1 = new Knight(Coordinate::B1);
	knight1->setIsWhite(true);
	pieces.push_back(knight1);

	std::cout << "About to make black bishop\n";
	bishopBlack = new Bishop(Coordinate::C1);
	bishopBlack->setIsWhite(true);
	pieces.push_back(bishopBlack);

	std::cout << "About to make black queen\n";
	queen = new Queen(Coordinate::D1);
	queen->setIsWhite(true);
	pieces.push_back(queen);

	std::cout << "About to make king\n";
	king = new King(Coordinate::E1);
	king->setIsWhite(true);
	pieces.push_back(king);

	std::cout << "About to make white bishop\n";
	bishopWhite = new Bishop(Coordinate::F1);
	bishopWhite->setIsWhite(true);
	pieces.push_back(bishopWhite);

	std::cout << "About to make second knight\n";
	knight2 = new Knight(Coordinate::G1);
	knight2->setIsWhite(true);
	pieces.push_back(knight2);

	std::cout << "About to make second rook\n";
	rook2 = new Rook(Coordinate::H1);
	rook2->setIsWhite(true);
	pieces.push_back(rook2);
}
