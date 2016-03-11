#include "King.h"




King::King(Coordinate coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void King::computeMovablePositions()
{
	//similar to Queens, but less

	int row = position.getRow();
	int column = position.getColumn();

	//top 
	if (row < 7)
	{
		movablePositions.push_back(computePosition(row + 1, column));
	}

	//bottom
	if (row > 0)
	{
		movablePositions.push_back(computePosition(row - 1, column));
	}

	//left
	if (column > 0)
	{
		movablePositions.push_back(computePosition(row, column - 1));
	}

	//right
	if (column < 7)
	{
		movablePositions.push_back(computePosition(row, column + 1));
	}

	//top-left
	if (row < 7  && column > 0)
	{
		movablePositions.push_back(computePosition(row + 1, column - 1));
	}

	//top-right
	if (row < 7 && column < 7)
	{
		movablePositions.push_back(computePosition(row + 1, column + 1));
	}

	//bottom-left
	if (row > 0 && column > 0)
	{
		movablePositions.push_back(computePosition(row - 1, column - 1));
	}

	//bottom-right
	if (row > 0 && column < 7)
	{
		movablePositions.push_back(computePosition(row - 1, column + 1));
	}
}
