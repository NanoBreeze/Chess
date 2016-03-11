#pragma once

//contains inforamtion related to each player, such as pieces and if it's his/her turn

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


class Player
{
public:
	Player();

	Piece* getPawn1() const;
	Piece* getPawn2() const;
	Piece* getPawn3() const;
	Piece* getPawn4() const;
	Piece* getPawn5() const;
	Piece* getPawn6() const;
	Piece* getPawn7() const;
	Piece* getPawn8() const;

	Piece* getRook1() const;
	Piece* getRook2() const;
	Piece* getKnight1() const;
	Piece* getKnight2() const;
	Piece* getBishopBlack() const;
	Piece* getBishopWhite() const;
	Piece* getQueen() const;
	Piece* getKing() const;

	bool getIsTurn() const;

	~Player();


protected:
	Piece* pawn1 = nullptr;
	Piece* pawn2 = nullptr;
	Piece* pawn3 = nullptr;
	Piece* pawn4 = nullptr;
	Piece* pawn5 = nullptr;
	Piece* pawn6 = nullptr;
	Piece* pawn7 = nullptr;
	Piece* pawn8 = nullptr;

	Piece* rook1 = nullptr;		//this is the rook that starts on left side
	Piece* rook2 = nullptr;	
	Piece* knight1 = nullptr;	//this is the knight that starts on left side
	Piece* knight2 = nullptr;
	Piece* bishopBlack = nullptr;	//bishop on black Square
	Piece* bishopWhite = nullptr;
	Piece* queen = nullptr;
	Piece* king= nullptr;

	bool isTurn;


};

