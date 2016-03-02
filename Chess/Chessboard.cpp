#include "Chessboard.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Chessboard::Chessboard()
{
	//use for loop instead of iterator because the loop count corresponds to a coordinate	
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			//consider making a map for Coordinate and default colour, requires refactoring, difficult to read, magic numbers, etc.

			squares[row][column].setCoordinate(static_cast<Coordinate>(8*(row)+column));
			squares[row][column].setDefaultColour(static_cast<Coordinate>(8 * row  + column ));
			squares[row][column].setPosition(sf::Vector2f(350 - row*50, column * 50));
		}
		
	}
}

void Chessboard::delegateClick(int x, int y)
{
	//find column of square the click is on, refactor later, currently uses magic numbers, 50, because 50 is the size of each square!
	int column = x / 50;

	//ensure the column is from 0 to 7
	assert( (column >= 0) && (column < 8));

	//find the row
	int row = 7 - y / 50; 

	//ensure the row is from 0 to 7
	assert( (row >= 0) && (row < 8));

	std::cout << "The column is " << std::to_string(column) << " and the row is " << std::to_string(row);
}

