#include "Piece.h"




Piece::Piece()
{
}

Piece::Piece(Coordinate coordinate)
{

}

Coordinate Piece::getCoordinate() const
{
	return coordinate;
}

void Piece::setCoordinate(const Coordinate coordinate)
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	setPosition(sf::Vector2f(column * 50, 350 - row * 50));
	computeMoves();
}


std::vector<Coordinate> Piece::getMoves() const
{
	return moves;
}


void Piece::clearMoves()
{
	moves.clear();
}

bool Piece::getIsWhite() const
{
	return isWhite;
}

void Piece::setIsWhite(const bool isWhite)
{
	this->isWhite = isWhite;
}

std::string Piece::getSymbol() const
{
	return symbol;
}

