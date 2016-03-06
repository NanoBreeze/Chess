#pragma once

#include "Square.h"
#include <iostream>
#include <assert.h>
#include <vector>

//contains 64 Squares to represent a chessboard
class Chessboard
{
public:
	//sets up the board
	Chessboard();

	//removes all pointers
	~Chessboard();
	
	Piece* bishop = nullptr;

	//SHOULD BE PRIVATE array of the squares on a chessboard
	Square squares[8][8];

	//uses the mouse coordinates for click to decide which individual Square to call to handle the click, or even no Squares at all!
	//This is currently very coupled
	void delegateClick(int x, int y);

	void highlightMovableSquares();

private:
};

