#include "Knight.h"
#include "Board.h"


Knight::Knight(Coordinate coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void Knight::computeMovablePositions()
{
	//can optimize

	//first clear past movablePositions
	clearMovablePositions();

	int row = position.getRow();
	int column = position.getColumn();

	//2 up 1 left
	if (row + 2 <= 7 && column - 1 >= 0)
	{
		//1
		if (Board::squares[column - 1][row + 2].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 1][row + 2].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 2, column - 1));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 2, column - 1));
		}

	}
	
	//2 up 1 right
	if (row + 2 <= 7 && column + 1 <= 7)
	{
		//1
		if (Board::squares[column + 1][row + 2].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 1][row + 2].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 2, column + 1));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 2, column + 1));
		}

	}

	//1 up 2 left
	if (row + 1 <= 7 && column - 2 >= 0)
	{
		//1
		if (Board::squares[column - 2][row + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 2][row + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 1, column - 2));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 1, column - 2));
		}

	}

	//1 up 2 right
	if (row + 1 <= 7 && column + 2 <= 7)
	{
		//1
		if (Board::squares[column + 2][row + 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 2][row + 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row + 1, column + 2));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row + 1, column + 2));
		}
	}

	//1 down 2 left
	if (row - 1 >= 0 && column - 2 >= 0)
	{
		//1
		if (Board::squares[column - 2][row - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 2][row - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row -1, column - 2));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 1, column - 2));
		}
	}

	//1 down 2 right
	if (row - 1 >= 0 && column + 2 <= 7)
	{
		//1
		if (Board::squares[column + 2][row - 1].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 2][row - 1].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 1, column + 2));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 1, column + 2));
		}
	}

	//2 down 1 left
	if (row - 2 >= 0 && column - 1 >= 0)
	{
		//1
		if (Board::squares[column - 1][row - 2].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column - 1][row - 2].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 2, column - 1));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 2, column - 1));
		}
	}

	//2 down 1 right
	if (row - 2 >= 0 && column + 1 <= 7)
	{
		//1
		if (Board::squares[column + 1][row - 2].getPiece() != nullptr)
		{
			//a)
			if (Board::squares[column + 1][row - 2].getPiece()->getIsWhite() == this->isWhite)
			{
				//that square is not placed into movablePositions
			}
			//b)
			else
			{
				movablePositions.push_back(computePosition(row - 2, column + 1));

			}
		}
		else
		{
			movablePositions.push_back(computePosition(row - 2, column + 1));
		}
	}









}
