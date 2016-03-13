#include "Rook.h"
#include "Board.h"


Rook::Rook(Coordinate coordinate) : Piece(coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));

}

void Rook::computeMovablePositions()
{
	//first clear past movablePositions
	clearMovablePositions();

	//find row and column of coordinates
	int row1 = position.getRow();
	int column1 = position.getColumn();

	//can consider left and right into horizontal
	//compute left Squares

	while (column1 - 1>= 0)
	{
		if (Board::squares[column1 - 1][row1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column1 - 1][row1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row1, column1 - 1));
				break;
			}
		}

		movablePositions.push_back(computePosition(row1, column1 - 1));
		column1--;
	}

	//compute right Squares
	int row2 = position.getRow();
	int column2 = position.getColumn();

	while (column2 + 1 <= 7)
	{
		if (Board::squares[column2 + 1][row2].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column2 + 1][row2].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row2, column2 + 1));
				break;
			}
		}

		movablePositions.push_back(computePosition(row2, column2 + 1));
		column2++;
	}
		
	//compute top Squares
	int row3 = position.getRow();
	int column3 = position.getColumn();

	while (row3 + 1 <= 7)
	{
		if (Board::squares[column3][row3 + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column3][row3 + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row3 + 1, column3));
				break;
			}
		}

		movablePositions.push_back(computePosition(row3 + 1, column3));
		row3++;
	}

	//compute top Squares
	int row4 = position.getRow();
	int column4 = position.getColumn();

	while (row4 - 1  >= 0)
	{
		if (Board::squares[column4][row4 - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column4][row4 - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row4 - 1, column4));
				break;
			}
		}

		movablePositions.push_back(computePosition(row4 - 1, column4));
		row4--;
	}
}
