#include "Bishop.h"


//set coordinate and size
Bishop::Bishop()
{
	coordinate = Coordinate::B2;
	setSize(sf::Vector2f(20, 20));
}

//problem, in the moveableSquares, there are duplications of the current square the bishop is in
void Bishop::computeMovableSquares()
{
	//find row and column of coordinates
	int row1 = getRow();
	int column1 = getColumn();

	//compute top right squares, stop if row is over 7 or column is over 7
	while (row1 <= 7 && column1 <= 7)
	{
		movableSquares.push_back(computeCoordinate(row1, column1));

		//go to next row
		row1++;
		column1++;
	}
	
	//compute bottom left squares, stop if row is under 0 or column is under 0
	int row2 = getRow();
	int column2 = getColumn();

	while (row2 >= 0 && column2 >= 0)
	{
		movableSquares.push_back(computeCoordinate(row2, column2));

		//go to next row
		row2--;
		column2--;
	}

	//compute top left squares, stop if row is over 7 or column is under 0
	int row3 = getRow();
	int column3 = getColumn();

	while (row3 <= 7 && column3 >= 0)
	{
		movableSquares.push_back(computeCoordinate(row3, column3));

		//go to next row
		row3++;
		column3--;
	}

	//compute bottom right squares, stop if row is under 0 or column is over 7
	int row4 = getRow();
	int column4 = getColumn();

	while (row4 >= 0 && column4 <= 7)
	{
		movableSquares.push_back(computeCoordinate(row4, column4));
		

		//go to next row
		row4--;
		column4++;
	}

}
