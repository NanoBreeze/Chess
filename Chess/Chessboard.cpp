#include "Chessboard.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Chessboard::Chessboard() : bishop(new Bishop())
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

	//sets the bishop
	bishop->setCoordinate(Coordinate::D5);
	squares[3][4].setBishop(bishop);
	highlightBishopMovableSquares();
	
}

Chessboard::~Chessboard()
{
	delete bishop;
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

	//unhighlight all other squares (this implementation si really inefficient because we're looping and there's only one square that can possibly be highlighed at a time)
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			squares[i][j].unHighlight();
		}
	}
	
	//highlight the selected square
	squares[7-column][7-row].highlightSelected();

	//if the selected square contains a bishop, highlight its movable squares
	if (squares[7 - column][7 - row].getBishop() != nullptr)
	{
		highlightBishopMovableSquares();
	}
}

void Chessboard::highlightBishopMovableSquares()
{
	std::vector<Coordinate> movableSquares = bishop->getMovableSquares();

	for (Coordinate coordinate: movableSquares)
	{
		//get row and column entry
		int row = Helper::getRowFromCoordinate(coordinate);
		int column = Helper::getColumnFromCoordinate(coordinate);

		squares[7-column][7 - row].highlightIsLegalMove();
	}
}

