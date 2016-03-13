#include "Queen.h"
#include "Board.h"


Queen::Queen(Coordinate coordinate) 
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}


void Queen::computeMovablePositions()
{
	//first clear past movablePositions
	clearMovablePositions();

	//This is a conglomeration of Rook's and Bishop's moves

/* ================== ROOK ====================*/
	//find row and column of coordinates
	int row1 = position.getRow();
	int column1 = position.getColumn();

	//can consider left and right into horizontal
	//compute left Squares

	while (column1 - 1 >= 0)
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

	while (row4 - 1 >= 0)
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

	/* ====================== BISHOP ===================== */

	//find row and column of coordinates
	int row5 = position.getRow();
	int column5 = position.getColumn();

	//compute top right squares, stop if row is over 7 or column is over 7
	while (row5 + 1 <= 7 && column5 + 1 <= 7)
	{
		if (Board::squares[column5 + 1][row5 + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column5 + 1][row5 + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row5 + 1, column5 + 1));
				break;
			}
		}

		movablePositions.push_back(computePosition(row5 + 1, column5 + 1));

		//go to next row
		row5++;
		column5++;
	}

	//compute bottom left squares, stop if row is under 0 or column is under 0
	int row6 = position.getRow();
	int column6 = position.getColumn();

	while (row6 - 1 >= 0 && column6 - 1 >= 0)
	{
		if (Board::squares[column6 - 1][row6 - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column6 - 1][row6 - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row6 - 1, column6 - 1));
				break;
			}
		}


		movablePositions.push_back(computePosition(row6 - 1, column6 - 1));

		//go to next row
		row6--;
		column6--;
	}

	//compute top left squares, stop if row is over 7 or column is under 0
	int row7 = position.getRow();
	int column7 = position.getColumn();

	while (row7 + 1 <= 7 && column7 - 1 >= 0)
	{
		if (Board::squares[column7 - 1][row7 + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column7 - 1][row7 + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row7 + 1, column7 - 1));
				break;
			}
		}

		movablePositions.push_back(computePosition(row7 + 1, column7 - 1));

		//go to next row
		row7++;
		column7--;
	}

	//compute bottom right squares, stop if row is under 0 or column is over 7
	int row8 = position.getRow();
	int column8 = position.getColumn();

	while (row8 - 1 >= 0 && column8 + 1 <= 7)
	{
		if (Board::squares[column8 + 1][row8 - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column8 + 1][row8 - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				break;
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row8 - 1, column8 + 1));
				break;
			}
		}

		movablePositions.push_back(computePosition(row8 - 1, column8 + 1));

		//go to next row
		row8--;
		column8++;
	}

}
