#include "King.h"
#include "Board.h"




King::King(Coordinate coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void King::computeMovablePositions()
{
	//first clear past movablePositions
	clearMovablePositions();

	//similar to Queens, but less

	int row = position.getRow();
	int column = position.getColumn();

	//top 
	if (row + 1 <= 7)
	{
		//1
		if (Board::squares[column][row + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column][row + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 1, column));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 1, column));
		}
	}

	//bottom
	if (row - 1 >= 0)
	{
		//1
		if (Board::squares[column][row - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column][row - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 1, column));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 1, column));

		}

	}

	//left
	if (column - 1 >= 0)
	{
		//1
		if (Board::squares[column - 1][row].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 1][row].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row, column - 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row , column - 1));
		}
	}

	//right
	if (column  + 1 <= 7)
	{
		//1
		if (Board::squares[column + 1][row].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 1][row].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row, column + 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row, column + 1));
		}
	}

	//top-left
	if (row + 1 <= 7  && column-1 >= 0)
	{
		//1
		if (Board::squares[column - 1][row + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 1][row + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 1, column - 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 1, column - 1));
		}
	}

	//top-right
	if (row + 1 <= 7 && column + 1 <= 7)
	{
		//1
		if (Board::squares[column + 1][row + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 1][row + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 1, column + 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 1, column + 1));
		}
	}

	//bottom-left
	if (row - 1 >= 0 && column - 1 >= 0)
	{

		//1
		if (Board::squares[column - 1][row - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 1][row - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 1, column - 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 1, column - 1));
		}
	}

	//bottom-right
	if (row - 1 >= 0 && column + 1 <= 7)
	{
		//1
		if (Board::squares[column + 1][row - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 1][row - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 1, column + 1));
			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 1, column + 1));
		}
	}
}
