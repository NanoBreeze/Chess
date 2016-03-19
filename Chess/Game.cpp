#include "Game.h"
#include "Board.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Game::Game()
{
	std::cout << "About to make white player";
	whitePlayer = new WhitePlayer();
	board.addPiecesToSquares(whitePlayer->getPieces());

	std::cout << "About to make black player";
	blackPlayer = new BlackPlayer();
	board.addPiecesToSquares(blackPlayer->getPieces());

}

Game::~Game()
{
	delete whitePlayer;
	delete blackPlayer;
}

void Game::delegateClick(const int& x, const int& y)
{
	auto selectedCoordinate = getCoordinateFromCursor(x, y);


	//unhighlight all other squares (this implementation si really inefficient because we're looping and there's only one square that can possibly be highlighed at a time)
	for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
	{
		board[coordinate].showDefaultColour();
	}


	//highlight the selected square, important that this part comes second
	board[selectedCoordinate].showSelectedColour();

	//compute the Coordinates the piece can move to and then highligh those coordinates
	if (board[selectedCoordinate].getPiece())
	{
		auto moves = board[selectedCoordinate].getPiece()->computeMoves();
		board.highlightLegalSquares(moves);
	}


	/*
	When the user clicks a Square,
	a) if there are no Square already selected (typically for start of game or c1), the clicked Square becomes the selected Square
	b) if there already is a selected Square
		b1) and that Square has no piece, then the clicked Square becomes the selected Square
		b2) and that Square already has a piece then:
			b2.1) if the clicked Square is a movable Square of that piece, move that piece and remove the selected Square
			b2.2) if the clicked Square is not a movable Square of that piece, set the clicked Square to be the selected Square
	*/

	Square* selectedSquare = &board[selectedCoordinate];


	//case a)
	if (stateManager.getSelectedSquare() == nullptr)
	{
		stateManager.setSelectedSquare(selectedSquare);
	}

	//case b)
	else
	{
		//case b1)
		if (stateManager.getSelectedSquare()->getPiece() == nullptr)
		{
			stateManager.setSelectedSquare(selectedSquare);
		}

		//case b2)
		else
		{
			auto stateManagerPiece = stateManager.getSelectedSquare()->getPiece();
			//movable positions of the already clicked Square
			auto moves = stateManagerPiece->getMoves();

			//case b2.1)
			if(std::find(moves.cbegin(), moves.cend(), selectedSquare->getCoordinate()) != moves.cend())
			{
				//move the Piece and add this Turn to the turns stack in StateManager

				Turn turn;
				turn.setPieceMoved(stateManagerPiece);
				turn.setFromCoordinate(stateManagerPiece->getCoordinate());
				turn.setToCoordinate(selectedSquare->getCoordinate());
				stateManager.getTurns().push(turn);


				//set Piece's new location
				stateManagerPiece->setCoordinate(selectedSquare->getCoordinate());

				// set new square with this piece and remove piece from previous square 
				selectedSquare->setPiece(stateManagerPiece);

				stateManager.getSelectedSquare()->removePiece();

				//remove selected Square
				stateManager.removeSelectedSquare();
			}

			//case b2.2
			else
			{
				stateManager.setSelectedSquare(selectedSquare);
			}
		}
	}
}


Coordinate Game::getCoordinateFromCursor(const int& x, const int& y) const
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

	//we find positions based on coordinate, so we switch the column and row to Coordinate
	return static_cast<Coordinate> (row * 8 + column);
}
