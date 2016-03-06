#include "Rook.h"



Rook::Rook()
{
}

void Rook::computeMovableSquares()
{
	//find row and column of coordinates
	int row1 = position.getRow();
	int column1 = position.getColumn();

	//can consider left and right into horizontal
	//compute left Squares

	while (column1 >= 0)
	{
		movableSquares.push_back(computeCoordinate(row1, column1));
		column1--;
	}

	//compute right Squares
	int row2 = position.getRow();
	int column2 = position.getColumn();

	while (column2 <= 7)
	{
		movableSquares.push_back(computeCoordinate(row2, column2));
		column2++;
	}
		
	//compute top Squares
	int row3 = position.getRow();
	int column3 = position.getColumn();

	while (row3 <= 7)
	{
		movableSquares.push_back(computeCoordinate(row3, column3));
		row3++;
	}

	//compute top Squares
	int row4 = position.getRow();
	int column4 = position.getColumn();

	while (row4 >= 0)
	{
		movableSquares.push_back(computeCoordinate(row4, column4));
		row4--;
	}
}
