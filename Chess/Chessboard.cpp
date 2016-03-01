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
			squares[row][column].setPosition(sf::Vector2f(500 - row*50, column * 50));
		}
		
	}
}
