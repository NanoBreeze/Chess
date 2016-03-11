#include "Pawn.h"




Pawn::Pawn(Coordinate coordinate)
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

void Pawn::computeMovablePositions()
{
	//REQUIRES CHANGING TO ACCOUNT FOR INITIAL possible 2 moves, and promotions. 
	//now only move one piece up. 

	int row = position.getRow();
	int column = position.getColumn();

	if (row < 7)
	{
		movablePositions.push_back(computePosition(row + 1, column));
	}
}
