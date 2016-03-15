#include "Game.h"



//sets up the board by adding 64 Squares, giving them coordinates and default colours
Game::Game() 
{
	//use for loop instead of iterator because the loop count corresponds to a coordinate
	for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
	{
		board[coordinate].setCoordinate(coordinate);
		board[coordinate].setDefaultColour(coordinate);
		//HOW TO SET THE POSITION??? THIS IS FROM PREVIOUS VALUE

		int row = (int)coordinate / 8;
		int column = (int)coordinate % 8;

		board[coordinate].setPosition(sf::Vector2f(column * 50, 350 - row * 50));

		//Board::squares[column][row].setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	}

	std::cout << "About to make white player";
	whitePlayer = new WhitePlayer();

	std::cout << "About to make black player";
	blackPlayer = new BlackPlayer();

	//sets the White player's pieces, eventually this setting process will become easier.

	board[Coordinate::A1].setPiece(whitePlayer->getRook1());
	board[Coordinate::B1].setPiece(whitePlayer->getKnight1());
	board[Coordinate::C1].setPiece(whitePlayer->getBishopBlack());
	board[Coordinate::D1].setPiece(whitePlayer->getQueen());
	board[Coordinate::E1].setPiece(whitePlayer->getKing());
	board[Coordinate::F1].setPiece(whitePlayer->getBishopWhite());
	board[Coordinate::G1].setPiece(whitePlayer->getKnight2());
	board[Coordinate::H1].setPiece(whitePlayer->getRook2());

	board[Coordinate::A2].setPiece(whitePlayer->getPawn1());
	board[Coordinate::B2].setPiece(whitePlayer->getPawn2());
	board[Coordinate::C2].setPiece(whitePlayer->getPawn3());
	board[Coordinate::D2].setPiece(whitePlayer->getPawn4());
	board[Coordinate::E2].setPiece(whitePlayer->getPawn5());
	board[Coordinate::F2].setPiece(whitePlayer->getPawn6());
	board[Coordinate::G2].setPiece(whitePlayer->getPawn7());
	board[Coordinate::H2].setPiece(whitePlayer->getPawn8());
	
	//sets the Black player's pieces, eventually this setting process will be easier

	board[Coordinate::H8].setPiece(blackPlayer->getRook1());
	board[Coordinate::G8].setPiece(blackPlayer->getKnight1());
	board[Coordinate::F8].setPiece(blackPlayer->getBishopBlack());
	board[Coordinate::E8].setPiece(blackPlayer->getQueen());
	board[Coordinate::D8].setPiece(blackPlayer->getKing());
	board[Coordinate::C8].setPiece(blackPlayer->getBishopWhite());
	board[Coordinate::B8].setPiece(blackPlayer->getKnight2());
	board[Coordinate::A8].setPiece(blackPlayer->getRook2());

	board[Coordinate::H7].setPiece(blackPlayer->getPawn1());
	board[Coordinate::G7].setPiece(blackPlayer->getPawn2());
	board[Coordinate::F7].setPiece(blackPlayer->getPawn3());
	board[Coordinate::E7].setPiece(blackPlayer->getPawn4());
	board[Coordinate::D7].setPiece(blackPlayer->getPawn5());
	board[Coordinate::C7].setPiece(blackPlayer->getPawn6());
	board[Coordinate::B7].setPiece(blackPlayer->getPawn7());
	board[Coordinate::A7].setPiece(blackPlayer->getPawn8());
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
		board[coordinate].unHighlight();
	}
	/*for (int column = 0; column < 8; column++)
	{
		for (int row = 0; row < 8; row++)
		{
			Board::squares[column][row].unHighlight();
		}
	}
*/

	//REWRITE THIS PART TO BE MAINTAINABLE

	auto n = board[selectedCoordinate].getPiece();
	
	//call computeMovablePosition of the piece if it exists again, 
	if (board[selectedCoordinate].getPiece())
	{
		board[selectedCoordinate].getPiece()->computeMoves();
	}

	//highlight the selected square, important that this part comes second
	board[selectedCoordinate].highlightSelected();

	highlightMovableSquares(board[selectedCoordinate].getPiece());


	//auto n = board[column][row].getPiece();
	//
	////call computeMovablePosition of the piece if it exists again, 
	//if (Board::squares[column][row].getPiece())
	//{
	//	Board::squares[column][row].getPiece()->computeMoves();
	//}

	////highlight the selected square, important that this part comes second
	//Board::squares[column][row].highlightSelected();

	//highlightMovableSquares(Board::squares[column][row].getPiece());

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
		Square* clickedSquare = &board[selectedCoordinate];
		//auto clickedSquare = &Board::squares[column][row];
		stateManager.setSelectedSquare(clickedSquare);

		
	}
	//case b)
	else
	{
		Square* clickedSquare = &board[selectedCoordinate];
		//auto clickedSquare = &Board::squares[column][row];

		//case b1)
		if (stateManager.getSelectedSquare()->getPiece() == nullptr)
		{
			stateManager.setSelectedSquare(clickedSquare);
		}
		//case b2)
		else
		{
			//movable positions of the already clicked Square
			auto moves = stateManager.getSelectedSquare()->getPiece()->getMoves();
			
			bool clickedSquareIsMovableSquare = false;

			for (auto coordinate : moves)
			{
				auto clickedSquareCoordinate = clickedSquare->getCoordinate();

				//case b2.1)
				if (coordinate == clickedSquare->getCoordinate())
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
				stateManager.getSelectedSquare()->getPiece()->clearMoves();

				//set Piece's new location
				stateManager.getSelectedSquare()->getPiece()->setCoordinate(clickedSquare->getCoordinate());
				
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

void Game::highlightMovableSquares(Piece* piece)
{
	//we check for nullptr because this function is called on any clicked Square, even if it doesn't contain a Piece (piece != nullptr) 
	if (piece != nullptr)
	{
		auto moves = piece->getMoves();

		for (auto coordinate : moves)
		{
			board[coordinate].highlightIsLegalMove();
			//Board::getSquare(coordinate).highlightIsLegalMove();
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


