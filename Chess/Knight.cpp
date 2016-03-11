#include "Knight.h"


Knight::Knight(Coordinate coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void Knight::computeMovablePositions()
{
	//can optimize

	int row = position.getRow();
	int column = position.getColumn();

	//2 up 1 left
	if (row + 2 <= 7 && column - 1 >= 0)
	{
		movablePositions.push_back(computePosition(row + 2, column - 1));
	}
	
	//2 up 1 right
	if (row + 2 <= 7 && column + 1 <= 7)
	{
		movablePositions.push_back(computePosition(row + 2, column + 1));
	}

	//1 up 2 left
	if (row + 1 <= 7 && column - 2 >= 0)
	{
		movablePositions.push_back(computePosition(row + 1, column - 2));
	}

	//1 up 2 right
	if (row + 1 <= 7 && column + 2 <= 7)
	{
		movablePositions.push_back(computePosition(row + 1, column + 2));
	}

	//1 down 2 left
	if (row - 1 >= 0 && column - 2 >= 0)
	{
		movablePositions.push_back(computePosition(row - 1, column - 2));
	}

	//1 down 2 right
	if (row - 1 >= 0 && column + 2 <= 7)
	{
		movablePositions.push_back(computePosition(row - 1, column + 2));
	}

	//2 down 1 left
	if (row - 2 >= 0 && column - 1 >= 0)
	{
		movablePositions.push_back(computePosition(row - 2, column - 1));
	}

	//2 down 1 right
	if (row - 2 >= 0 && column + 1 <= 7)
	{
		movablePositions.push_back(computePosition(row - 2, column + 1));
	}









}
