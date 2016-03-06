#include "Rook.h"



Rook::Rook()
{
}

void Rook::computeMovablePositions()
{
	//find row and column of coordinates
	int row1 = position.getRow();
	int column1 = position.getColumn();

	//can consider left and right into horizontal
	//compute left Squares

	while (column1 >= 0)
	{
		movablePositions.push_back(computePosition(row1, column1));
		column1--;
	}

	//compute right Squares
	int row2 = position.getRow();
	int column2 = position.getColumn();

	while (column2 <= 7)
	{
		movablePositions.push_back(computePosition(row2, column2));
		column2++;
	}
		
	//compute top Squares
	int row3 = position.getRow();
	int column3 = position.getColumn();

	while (row3 <= 7)
	{
		movablePositions.push_back(computePosition(row3, column3));
		row3++;
	}

	//compute top Squares
	int row4 = position.getRow();
	int column4 = position.getColumn();

	while (row4 >= 0)
	{
		movablePositions.push_back(computePosition(row4, column4));
		row4--;
	}
}
