#pragma once

#include "Square.h"
#include "StateManager.h"
#include <iostream>
#include <assert.h>

#include <vector>

//will remove
#include <SFML\Graphics.hpp>

//contains 64 Squares to represent a chessboard
class Chessboard
{
public:
	//sets up the board
	Chessboard();

	//removes all pointers
	~Chessboard();
	
	Piece* bishop = nullptr;
	Piece* rook = nullptr;
	Piece* queen = nullptr;

	//SHOULD BE PRIVATE array of the squares on a chessboard
	Square squares[8][8];

	//uses the mouse coordinates for click to decide which individual Square to call to handle the click, or even no Squares at all!
	//This is currently very coupled
	void delegateClick(int x, int y);
	
	//highlights the squares the passed in piece can move to. Intended to be used by delegateClick. 
	//If the clicked Square has a piece, then highlight all the squares it can move to
	void highlightMovableSquares(Piece*);

	//contains info relevant to the state of the game.
	StateManager stateManager;

private:
};

