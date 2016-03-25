#pragma once

#include "Square.h"
#include "StateManager.h"
#include <iostream>
#include <assert.h>
#include "WhitePlayer.h"
#include "BlackPlayer.h"

#include "Board.h"
#include <vector>
#include <algorithm>

#include "MovesDisplay.h"

//will remove
#include <SFML\Graphics.hpp>

//contains 64 Squares to represent a chessboard
class Game
{
public:
	//sets up the board, and players
	Game();

	//removes all pointers
	~Game();
	
	//contains pieces and info related to the white player
	Player* whitePlayer = nullptr;

	//contains pieces and info related to the black player
	Player* blackPlayer = nullptr;

	//contains the Squares. This is where the visual action goes on and the 2D array of Squares reside
	Board board = Board::getInstance();

	//contains info relevant to the state of the game.
	StateManager stateManager = StateManager::getInstance();

	//manages selecting a Square or Piece, (thus moving, etc), works with stateManager getCoordinateFromCursor()
	void delegateClick(const int& x, const int& y);

private:

	//Returns the coordinate associated with the pixel that the cursor clicked. 
	Coordinate getCoordinateFromCursor(const int&, const int&) const;

};

