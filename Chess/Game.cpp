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

void Game::delegateClick(const int& x, const int& y, sf::TcpSocket& socket, const bool solo)
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
			if (std::find(moves.cbegin(), moves.cend(), selectedSquare->getCoordinate()) != moves.cend())
			{
				//move the Piece and add this Turn to the turns stack in StateManager

				Turn turn;
				turn.setPieceMoved(stateManagerPiece);
				turn.setFromCoordinate(stateManagerPiece->getCoordinate());
				turn.setToCoordinate(selectedSquare->getCoordinate());

				//there is a piece to be captured
				if (selectedSquare->getPiece() != nullptr)
				{
					turn.setCapturedPiece(selectedSquare->getPiece());
				}
				stateManager.getTurns().push(turn);

				if (solo == false)
				{
					//send the coordinates of this move to the other player
					const int msgSize = 5;
					char message[msgSize];

					std::string from = std::to_string(static_cast<int>(stateManagerPiece->getCoordinate()));
					std::string to = std::to_string(static_cast<int>(selectedSquare->getCoordinate()));

					int charIndex = 0;

					//fill in the from coordinates into the char array
					for (int i = 0; i < from.length(); i++)
					{
						message[charIndex] = from[i];
						charIndex++;
					}

					message[charIndex] = ',';
					charIndex++;

					//fill in the to coordinates into the char array
					for (int i = 0; i < to.length(); i++)
					{
						message[charIndex] = to[i];
						charIndex++;
					}

					//fill in the remaining space with blanks
					for (charIndex; charIndex < msgSize; charIndex++)
					{
						message[charIndex] = '_';
					}

					if (socket.send(message, msgSize) != sf::Socket::Done)
					{
						std::cout << "The message couldn't be sent";
					}
					else
					{
						std::cout << "Message containing move sent";
					}
				}

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


void Game::delegateReceivedMove(const char data[], const int size)
{
	//get the two coordinates, which are delimited with ,
	std::string from = "";
	std::string to = "";

	int charIndex = 0;

	//get from coordinate
	for (charIndex; charIndex < size; charIndex++)
	{
		if (data[charIndex] != ',')
		{
			from += data[charIndex];
		}
		else { break; }
	}

	charIndex++; //skip the ,

	//get to coordinate, stop at blanks, if they appear
	for (charIndex; charIndex < size; charIndex++)
	{
		if (data[charIndex] != '_')
		{
			to += data[charIndex];
		}
		else { break; }
	}

	//get the coordinate values
	int fromInt = std::stoi(from);
	int toInt = std::stoi(to);

	Coordinate fromCoordinate = static_cast<Coordinate>(fromInt);
	Coordinate toCoordinate = static_cast<Coordinate>(toInt);

	Piece* pieceAtFrom = board[fromCoordinate].getPiece();

	//update the Turn list, this piece of code is almost identical to the one in case 2.1 in delegateClick
	Turn turn;
	turn.setPieceMoved(pieceAtFrom);
	turn.setFromCoordinate(fromCoordinate);
	turn.setToCoordinate(toCoordinate);

	//there is a piece to be captured
	if (board[toCoordinate].getPiece() != nullptr)
	{
		turn.setCapturedPiece(board[toCoordinate].getPiece());
	}
	stateManager.getTurns().push(turn);


	//remove piece at the to's coordinate, set the piece at the from coordinate to be at the to's coordinate, remove piece at from's coordinate
	pieceAtFrom->setCoordinate(toCoordinate);

	board[toCoordinate].removePiece();
	board[toCoordinate].setPiece(pieceAtFrom);
	board[fromCoordinate].removePiece();
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

	std::cout << "The column is " << std::to_string(column) << " and the row is " << std::to_string(row) << std::endl;

	//we find positions based on coordinate, so we switch the column and row to Coordinate
	return static_cast<Coordinate> (row * 8 + column);
}
