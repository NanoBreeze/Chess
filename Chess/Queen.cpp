#include "Queen.h"



Queen::Queen(Coordinate coordinate) 
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}


void Queen::computeMovablePositions()
{
	//This is a conglomeration of Rook's and Bishop's moves

/* ================== ROOK ====================*/
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

	/* ====================== BISHOP ===================== */

	//find row and column of coordinates
	int row5 = position.getRow();
	int column5 = position.getColumn();

	//compute top right squares, stop if row is over 7 or column is over 7
	while (row5 <= 7 && column5 <= 7)
	{
		movablePositions.push_back(computePosition(row5, column5));

		//go to next row
		row5++;
		column5++;
	}

	//compute bottom left squares, stop if row is under 0 or column is under 0
	int row6 = position.getRow();
	int column6 = position.getColumn();

	while (row6 >= 0 && column6 >= 0)
	{
		movablePositions.push_back(computePosition(row6, column6));

		//go to next row
		row6--;
		column6--;
	}

	//compute top left squares, stop if row is over 7 or column is under 0
	int row7 = position.getRow();
	int column7 = position.getColumn();

	while (row7 <= 7 && column7 >= 0)
	{
		movablePositions.push_back(computePosition(row7, column7));

		//go to next row
		row7++;
		column7--;
	}

	//compute bottom right squares, stop if row is under 0 or column is over 7
	int row8 = position.getRow();
	int column8 = position.getColumn();

	while (row8 >= 0 && column8 <= 7)
	{
		movablePositions.push_back(computePosition(row8, column8));

		//go to next row
		row8--;
		column8++;
	}

}
