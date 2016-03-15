#pragma once

#include "Square.h"
#include "StateManager.h"
#include <iostream>
#include <assert.h>
#include "WhitePlayer.h"
#include "BlackPlayer.h"

#include "Board.h"
#include <vector>

//will remove
#include <SFML\Graphics.hpp>

//contains 64 Squares to represent a chessboard
class Game
{
public:
	//sets up the board
	Game();

	//removes all pointers
	~Game();
	
	//contains pieces and info related to the white player
	Player* whitePlayer = nullptr;

	//contains pieces and info related to the black player
	Player* blackPlayer = nullptr;

	Board board = Board::Instance();

	//uses the mouse coordinates for click to decide which individual Square to call to handle the click, or even no Squares at all!
	//This is currently very coupled
	void delegateClick(const int& x, const int& y);
	
	//highlights the squares the passed in piece can move to. Intended to be used by delegateClick. 
	//If the clicked Square has a piece, then highlight all the squares it can move to
	void highlightMovableSquares(Piece*);

	//contains info relevant to the state of the game.
	StateManager stateManager;

private:
	//Returns the coordinate associated with the pixel that the cursor clicked. 
	Coordinate getCoordinateFromCursor(const int&, const int&) const;
};

