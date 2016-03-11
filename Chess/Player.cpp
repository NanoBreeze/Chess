#include "Player.h"



Player::Player() 
{
}

Piece * Player::getPawn1() const
{
	return pawn1;
}

Piece * Player::getPawn2() const
{
	return pawn2;
}

Piece * Player::getPawn3() const
{
	return pawn3;
}

Piece * Player::getPawn4() const
{
	return pawn4;
}

Piece * Player::getPawn5() const
{
	return pawn5;
}

Piece * Player::getPawn6() const
{
	return pawn6;
}

Piece * Player::getPawn7() const
{
	return pawn7;
}

Piece * Player::getPawn8() const
{
	return pawn8;
}

Piece * Player::getRook1() const
{
	return rook1;
}

Piece * Player::getRook2() const
{
	return rook2;
}

Piece * Player::getKnight1() const
{
	return knight1;
}

Piece * Player::getKnight2() const
{
	return knight2;
}

Piece * Player::getBishopBlack() const
{
	return bishopBlack;
}

Piece * Player::getBishopWhite() const
{
	return bishopWhite;
}

Piece * Player::getQueen() const
{
	return queen;
}

Piece * Player::getKing() const
{
	return king;
}

bool Player::getIsTurn() const
{
	return isTurn;
}

Player::~Player()
{
	delete pawn1;
	delete pawn2;
	delete pawn3;
	delete pawn4;
	delete pawn5;
	delete pawn6;
	delete pawn7;
	delete pawn8;

	delete rook1;
	delete rook2;
	delete knight1;
	delete knight2;
	delete bishopBlack;
	delete bishopWhite;
	delete queen;
	delete king;



}
