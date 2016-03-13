#include "Pawn.h"
#include "Board.h"




Pawn::Pawn(Coordinate coordinate) : hasYetToMove(true)
{
	Piece::setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void Pawn::setPosition(const Position position)
{
	Piece::setPosition(position);
	hasYetToMove = false;
}

void Pawn::computeMovablePositions()
{

	//first clear past movablePositions
	clearMovablePositions();

	//REQUIRES CHANGING TO ACCOUNT FOR and promotions. 

	int row = position.getRow();
	int column = position.getColumn();

	if (isWhite)
	{
		if (row + 1 <= 7)
		{
			//capturing 1 up, 1 left piece
			if (Board::squares[column - 1][row + 1].getPiece() != nullptr)
			{
				if (Board::squares[column - 1][row + 1].getPiece()->getIsWhite() != this->isWhite)
				{
					movablePositions.push_back(computePosition(row + 1, column - 1));

				}
			}

			//capturing 1 up, 1 right piece
			if (Board::squares[column + 1][row + 1].getPiece() != nullptr)
			{
				if (Board::squares[column + 1][row + 1].getPiece()->getIsWhite() != this->isWhite)
				{
					movablePositions.push_back(computePosition(row + 1, column + 1));

				}

			}

			//moving
			if (hasYetToMove)
			{
				if (Board::squares[column][row + 1].getPiece() != nullptr)
				{
					//don't add any positions to computePosition
				}
				else if (Board::squares[column][row + 1].getPiece() == nullptr && Board::squares[column][row + 2].getPiece() != nullptr)
				{
					movablePositions.push_back(computePosition(row + 1, column));
				}
				else if (Board::squares[column][row + 1].getPiece() == nullptr && Board::squares[column][row + 2].getPiece() == nullptr)
				{
					movablePositions.push_back(computePosition(row + 1, column));
					movablePositions.push_back(computePosition(row + 2, column));
				}
			}
			else
			{
				if (Board::squares[column][row + 1].getPiece() == nullptr)
				{
					movablePositions.push_back(computePosition(row + 1, column));
				}
			}
		}
	}
	else
	{
		if (row - 1 >= 0)
		{
			//capturing 1 up, 1 left piece
			if (Board::squares[column - 1][row - 1].getPiece() != nullptr)
			{
				if (Board::squares[column - 1][row - 1].getPiece()->getIsWhite() != this->isWhite)
				{
					movablePositions.push_back(computePosition(row - 1, column - 1));

				}
			}

			//capturing 1 up, 1 right piece
			if (Board::squares[column + 1][row - 1].getPiece() != nullptr)
			{
				if (Board::squares[column + 1][row - 1].getPiece()->getIsWhite() != this->isWhite)
				{
					movablePositions.push_back(computePosition(row - 1, column + 1));

				}

			}

			//moving
			if (hasYetToMove)
			{
				if (Board::squares[column][row - 1].getPiece() != nullptr)
				{
					//don't add any positions to computePosition
				}
				else if (Board::squares[column][row - 1].getPiece() == nullptr && Board::squares[column][row - 2].getPiece() != nullptr)
				{
					movablePositions.push_back(computePosition(row - 1, column));
				}
				else if (Board::squares[column][row - 1].getPiece() == nullptr && Board::squares[column][row - 2].getPiece() == nullptr)
				{
					movablePositions.push_back(computePosition(row - 1, column));
					movablePositions.push_back(computePosition(row - 2, column));
				}
			}
			else
			{
				if (Board::squares[column][row - 1].getPiece() == nullptr)
				{
					movablePositions.push_back(computePosition(row - 1, column));
				}
			}
		}
	}
	
	
}


