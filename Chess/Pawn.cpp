#include "Pawn.h"
#include "Board.h"




Pawn::Pawn(Coordinate coordinate) : hasYetToMove(true)
{
	this->coordinate = coordinate;

	auto m1 = board[Coordinate::B1];
	auto m2 = board[Coordinate::B2];
	auto m3 = board[Coordinate::B3];
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
			if (board[oneUp].getPiece() != nullptr)
			{
				//don't add any positions to computePosition
			}
			else if (board[oneUp].getPiece() == nullptr && board[twoUp].getPiece() != nullptr)
			{
				moves.push_back(oneUp);
			}
			else if (board[oneUp].getPiece() == nullptr && board[twoUp].getPiece() == nullptr)
			{
				moves.push_back(oneUp);
				moves.push_back(twoUp);
			}
		}
		else
		{
			if (board[oneUp].getPiece() == nullptr)
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

		if (downLeft != CoordinateHelper::getMostDownLeftCoordinate(coordinate) ||	downLeft != Coordinate::Invalid)
		{
			addCaptureMove(downLeft);
		}




		auto oneDown = CoordinateHelper::getCoordinateDown(coordinate);
		auto twoDown = CoordinateHelper::getCoordinateDown(oneDown);

		//moving
		if (hasYetToMove)
		{
			if (board[oneDown].getPiece() != nullptr)
			{
				//don't add any positions to computePosition
			}
			else if (board[oneDown].getPiece() == nullptr && board[twoDown].getPiece() != nullptr)
			{
				moves.push_back(oneDown);
			}
			else if (board[oneDown].getPiece() == nullptr && board[twoDown].getPiece() == nullptr)
			{
				moves.push_back(oneDown);
				moves.push_back(twoDown);
			}
		}
		else
		{
			if (board[oneDown].getPiece() == nullptr)
			{
				moves.push_back(oneDown);
			}
		}
	}
}


void Pawn::addCaptureMove(const Coordinate& coordinate)
{
	if (board[coordinate].getPiece() != nullptr)
	{
		if (board[coordinate].getPiece()->getIsWhite() != this->isWhite)
		{
			moves.push_back(coordinate);

		}
	}
}


