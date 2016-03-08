#include "Chessboard.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Chessboard::Chessboard() : bishop(new Bishop(Coordinate::D5)), rook(new Rook(Coordinate::G2))
{
	//use for loop instead of iterator because the loop count corresponds to a coordinate	
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			//consider making a map for Coordinate and default colour, requires refactoring, difficult to read, magic numbers, etc.

			squares[column][row].setPositionwithCoordinate(static_cast<Coordinate>(8 * row + column));
			squares[column][row].setDefaultColour(static_cast<Coordinate>(8 * row + column));
			squares[column][row].setPosition(sf::Vector2f(column * 50, 350 - row * 50));
		}
	}



	//sets the bishop
	//bishop->setPosition(Coordinate::D5);
	squares[3][4].setPiece(bishop);
	squares[6][1].setPiece(rook);

	//highlightMovableSquares();


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
	assert((column >= 0) && (column < 8));


	//find the row
	int row =  7 - y / 50;

	//ensure the row is from 0 to 7
	assert((row >= 0) && (row < 8));

	std::cout << "The column is " << std::to_string(column) << " and the row is " << std::to_string(row);

	//unhighlight all other squares (this implementation si really inefficient because we're looping and there's only one square that can possibly be highlighed at a time)
	for (int column = 0; column < 8; column++)
	{
		for (int row = 0; row < 8; row++)
		{
			squares[column][row].unHighlight();
		}
	}

	//highlight the selected square
	squares[column][row].highlightSelected();

	//REWRITE THIS PART TO CONTAIN CORRECT LOGIC

	/*if a piece had already been selected, move the selected piece to the newly clicked square
	If it hasn't already been selected, check if the piece in the newly selected piece exists. If so, display its
	movable squares and set it to be "selected", otherwise...Hmmmmm */

	//the first part of the if statement accounts for first click in game, in which the selectedSquare is nullptr
	if (stateManager.getSelectedSquare() != nullptr  && stateManager.getSelectedSquare()->getPiece() != nullptr)
	{
		//move the piece to the selected square, set piece in new square, remove piece from currently selected square,  set StateManager's "selectedSquare" to nullptr, graphics

		auto clickedSquare = squares[column][row];

		auto m = stateManager.getSelectedSquare();
		//Square and piece both need to change positions
		stateManager.getSelectedSquare()->getPiece()->setPosition(Coordinate::A1);

		clickedSquare.setPiece(stateManager.getSelectedSquare()->getPiece());
	

		//stateManager.getSelectedSquare()->removePiece();

		//auto n = stateManager.getSelectedSquare()->getPiece();

		//stateManager.removeSelectedSquare();

				
	}
	else
	{
		//if the selected square contains a piece, highlight its movable squares, and set it as "selectedPiece" in StateManager
		if (squares[column][row].getPiece() != nullptr)
		{
			Square clickedSquare_temporary = squares[column][row];
			
			auto a = clickedSquare_temporary.getPiece();
		
			highlightMovableSquares(clickedSquare_temporary.getPiece());


			
			//not working, not sure why stateManager.setSelectedSquare(&clickedSquare_temporary);
		
			stateManager.selectedSquare = &squares[column][row];
			auto b = stateManager.selectedSquare->getPiece();
		}

	}
}


void Chessboard::highlightMovableSquares(Piece* piece)
{
	std::vector<Position> movablePositions = piece->getMovablePositions();

	for (Position position : movablePositions)
	{
		assert(position.getColumn() >= 0); //this this is false, bad bad

		//get row and column entry
		int row = position.getRow();
		int column = position.getColumn();

		squares[column][row].highlightIsLegalMove();
	}
}

