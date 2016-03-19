#include "Turn.h"



Turn::Turn()
{
}


Turn::~Turn()
{
}

Piece * Turn::getPieceMoved() const
{
	return pieceMoved;
}

void Turn::setPieceMoved(Piece* pieceMoved)
{
	this->pieceMoved = pieceMoved;
}

Coordinate Turn::getFromCoordinate() const
{
	return fromCoordinate;
}

void Turn::setFromCoordinate(Coordinate fromCoordinate)
{
	this->fromCoordinate = fromCoordinate;
}

Coordinate Turn::getToCoordinate() const
{
	return toCoordinate;
}


void Turn::setToCoordinate(Coordinate toCoordinate)
{
	this->toCoordinate = toCoordinate;
}

Piece * Turn::getCapturedPiece() const
{
	return capturedPiece;
}

void Turn::setCapturedPiece(Piece* capturedPiece)
{
	this->capturedPiece = capturedPiece;
}
