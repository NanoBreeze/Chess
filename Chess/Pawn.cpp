#include "Pawn.h"
#include "Board.h"




Pawn::Pawn(Coordinate coordinate) : hasYetToMove(true)
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	setSize(sf::Vector2f(20, 20));
}

void Pawn::setCoordinate(const Coordinate position)
{
	Piece::setCoordinate(position);
	hasYetToMove = false;
}



void Pawn::computeMoves()
{
	//first clear past movablePositions
	clearMoves();

	//REQUIRES CHANGING TO ACCOUNT FOR and promotions. 

	if (isWhite)
	{
		//capturing 1 up, 1 right piece
		Coordinate upRight = CoordinateHelper::getCoordinateUpRight(coordinate);

		if (upRight != CoordinateHelper::getMostUpRightCoordinate(coordinate) || upRight != Coordinate::Invalid)
		{
			addCaptureMove(upRight);
		}

		//capturing 1 up, 1 left piece
		auto upLeft = CoordinateHelper::getCoordinateUpLeft(coordinate);

		if (upLeft != CoordinateHelper::getMostUpLeftCoordinate(coordinate) || upLeft != Coordinate::Invalid)
		{
			addCaptureMove(upLeft);
		}

		auto oneUp = CoordinateHelper::getCoordinateUp(coordinate);
		auto twoUp = CoordinateHelper::getCoordinateUp(oneUp);

		//moving
		if (hasYetToMove)
		{
			if (Board::getSquare(oneUp).getPiece() != nullptr)
			{
				//don't add any positions to computePosition
			}
			else if (Board::getSquare(oneUp).getPiece() == nullptr && Board::getSquare(twoUp).getPiece() != nullptr)
			{
				moves.push_back(oneUp);
			}
			else if (Board::getSquare(oneUp).getPiece() == nullptr && Board::getSquare(twoUp).getPiece() == nullptr)
			{
				moves.push_back(oneUp);
				moves.push_back(twoUp);
			}
		}
		else
		{
			if (Board::getSquare(oneUp).getPiece() == nullptr)
			{
				moves.push_back(oneUp);
			}
		}
	}

	else
	{
		//capturing 1 down, 1 right piece
		auto downRight = CoordinateHelper::getCoordinateDownRight(coordinate);

		if (downRight != CoordinateHelper::getMostDownRightCoordinate(coordinate) || downRight != Coordinate::Invalid)
		{
			addCaptureMove(downRight);
		}

		//capturing 1 down, 1 left piece
		auto downLeft = CoordinateHelper::getCoordinateDownLeft(coordinate);

		if (downLeft != CoordinateHelper::getMostDownLeftCoordinate(coordinate) || downLeft != Coordinate::Invalid)
		{
			addCaptureMove(downLeft);
		}




		auto oneDown = CoordinateHelper::getCoordinateDown(coordinate);
		auto twoDown = CoordinateHelper::getCoordinateDown(oneDown);

		//moving
		if (hasYetToMove)
		{
			if (Board::getSquare(oneDown).getPiece() != nullptr)
			{
				//don't add any positions to computePosition
			}
			else if (Board::getSquare(oneDown).getPiece() == nullptr && Board::getSquare(twoDown).getPiece() != nullptr)
			{
				moves.push_back(oneDown);
			}
			else if (Board::getSquare(oneDown).getPiece() == nullptr && Board::getSquare(twoDown).getPiece() == nullptr)
			{
				moves.push_back(oneDown);
				moves.push_back(twoDown);
			}
		}
		else
		{
			if (Board::getSquare(oneDown).getPiece() == nullptr)
			{
				moves.push_back(oneDown);
			}
		}
	}
}


void Pawn::addCaptureMove(const Coordinate& coordinate)
{
	if (Board::getSquare(coordinate).getPiece() != nullptr)
	{
		if (Board::getSquare(coordinate).getPiece()->getIsWhite() != this->isWhite)
		{
			moves.push_back(coordinate);

		}
	}
}


