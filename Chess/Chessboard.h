#pragma once

#include "Square.h"
#include <iostream>
#include <assert.h>

//contains 64 Squares to represent a chessboard
class Chessboard
{
public:
	//sets up the board
	Chessboard();

	//SHOULD BE PRIVATE array of the squares on a chessboard
	Square squares[8][8];

	//uses the mouse coordinates for click to decide which individual Square to call to handle the click, or even no Squares at all!
	//This is currently very coupled
	void delegateClick(int x, int y);
private:
};

