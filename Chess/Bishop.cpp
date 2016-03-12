#include "Bishop.h"
#include "Board.h"

//set coordinate and size
Bishop::Bishop(Coordinate coordinate) 
{
	setPosition(coordinate);
	setSize(sf::Vector2f(20, 20));
}

//problem, in the moveableSquares, there are duplications of the current square the bishop is in
void Bishop::computeMovablePositions()
{
	//first clear past movablePositions
	clearMovablePositions();

	//find row and column of coordinates
	int row1 = position.getRow();
	int column1 = position.getColumn();

	auto n = Board::squares[column1 + 1][row1 + 1].getPiece();

	//compute top right squares, stop if row is over 7 or column is over 7
	while (row1 + 1 <= 7 && column1 + 1<= 7 && Board::squares[column1 + 1][row1 + 1].getPiece() == nullptr)
	{
		movablePositions.push_back(computePosition(row1+1, column1+1));

		//go to next row
		row1++;
		column1++;
	}
	
	//compute bottom left squares, stop if row is under 0 or column is under 0
	int row2 = position.getRow();
	int column2 = position.getColumn();

	while (row2 >= 0 && column2 >= 0 && Board::squares[column2 - 1][row2 - 1].getPiece() == nullptr)
	{
		movablePositions.push_back(computePosition(row2, column2));

		//go to next row
		row2--;
		column2--;
	}

	//compute top left squares, stop if row is over 7 or column is under 0
	int row3 = position.getRow();
	int column3 = position.getColumn();

	while (row3 <= 7 && column3 >= 0 && Board::squares[column3 - 1][row3 + 1].getPiece() == nullptr)
	{
		movablePositions.push_back(computePosition(row3, column3));

		//go to next row
		row3++;
		column3--;
	}

	//compute bottom right squares, stop if row is under 0 or column is over 7
	int row4 = position.getRow();
	int column4 = position.getColumn();

	while (row4 >= 0 && column4 <= 7 && Board::squares[column4 + 1][row4 - 1].getPiece() == nullptr)
	{
		movablePositions.push_back(computePosition(row4, column4));

		//go to next row
		row4--;
		column4++;
	}

}
