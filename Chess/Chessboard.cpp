#include "Chessboard.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Chessboard::Chessboard() /*: bishop(new Bishop(Coordinate::D5)), rook(new Rook(Coordinate::G2)), queen(new Queen(Coordinate::B7))*/
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



	//sets the White player's pieces, eventually this setting process will become easier.

	squares[0][0].setPiece(whitePlayer.getRook1());
	squares[1][0].setPiece(whitePlayer.getKnight1());
	squares[2][0].setPiece(whitePlayer.getBishopBlack());
	squares[3][0].setPiece(whitePlayer.getQueen());
	squares[4][0].setPiece(whitePlayer.getKing());
	squares[5][0].setPiece(whitePlayer.getBishopWhite());
	squares[6][0].setPiece(whitePlayer.getKnight2());
	squares[7][0].setPiece(whitePlayer.getRook2());

	squares[0][1].setPiece(whitePlayer.getPawn1());
	squares[1][1].setPiece(whitePlayer.getPawn2());
	squares[2][1].setPiece(whitePlayer.getPawn3());
	squares[3][1].setPiece(whitePlayer.getPawn4());
	squares[4][1].setPiece(whitePlayer.getPawn5());
	squares[5][1].setPiece(whitePlayer.getPawn6());
	squares[6][1].setPiece(whitePlayer.getPawn7());
	squares[7][1].setPiece(whitePlayer.getPawn8());;




}

Chessboard::~Chessboard()
{

}

void Chessboard::delegateClick(int x, int y)
{
	//find column of square the click is on, refactor later, currently uses magic numbers, 50, because 50 is the size of each square!
	int column = x / 50;

	//ensure the column is from 0 to 7
	assert((column >= 0) && (column < 8));


	//find the row
	int row = 7 - y / 50;

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

	highlightMovableSquares(squares[column][row].getPiece());

	/*
	When the user clicks a Square,
	a) if there are no Square already selected (typically for start of game or c1), the clicked Square becomes the selected Square
	b) if there already is a selected Square
		b1) and that Square has no piece, then the clicked Square becomes the selected Square
		b2) and that Square already has a piece then:
			b2.1) if the clicked Square is a movable Square of that piece, move that piece and remove the selected Square
			b2.2) if the clicked Square is not a movable Square of that piece, set the clicked Square to be the selected Square
	*/

	//case a)
	if (stateManager.getSelectedSquare() == nullptr)
	{
		auto clickedSquare = &squares[column][row];
		stateManager.setSelectedSquare(clickedSquare);
	}
	//case b)
	else
	{
		auto clickedSquare = &squares[column][row];

		//case b1)
		if (stateManager.getSelectedSquare()->getPiece() == nullptr)
		{
			stateManager.setSelectedSquare(clickedSquare);
		}
		//case b2)
		else
		{
			//movable positions of the already clicked Square
			auto movablePositions = stateManager.getSelectedSquare()->getPiece()->getMovablePositions();



			auto j = stateManager.getSelectedSquare()->getPiece()->getMovablePositions()[0].getCoordinate();



			bool clickedSquareIsMovableSquare = false;

			for (auto position : movablePositions)
			{
				auto positionCoordinate = position.getCoordinate();
				auto clickedSquareCoordinate = clickedSquare->getPositionwithPosition().getCoordinate();

				//case b2.1)
				if (position.getCoordinate() == clickedSquare->getPositionwithPosition().getCoordinate())
				{
					clickedSquareIsMovableSquare = true;
				}
			}

			//case b2.1)
			if (clickedSquareIsMovableSquare)
			{
				//move the Piece

				//remove Piece's movablePositions. movablePositiosn is set every time setPosition is called. 
				//Thus, it's important to clear the movablePositions before setting the Piece's new position
				stateManager.getSelectedSquare()->getPiece()->clearMovablePositions();

				//set Piece's new location
				stateManager.getSelectedSquare()->getPiece()->setPosition(clickedSquare->getPositionwithPosition());


				// set new square with this piece and remove piece from previous square 
				clickedSquare->setPiece(stateManager.getSelectedSquare()->getPiece());
				stateManager.getSelectedSquare()->setPiece(nullptr);


				//remove selected Square
				stateManager.removeSelectedSquare();
			}
			//case b2.2
			else
			{
				stateManager.setSelectedSquare(clickedSquare);
			}
		}
	}
}

void Chessboard::highlightMovableSquares(Piece* piece)
{
	//we check for nullptr because this function is called on any clicked Square, even if it doesn't contain a Piece (piece != nullptr) 
	if (piece != nullptr)
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

}


