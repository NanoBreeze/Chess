#pragma once

#include "CustomButton.h"
#include <fstream>
#include <iostream>
#include "Board.h"
#include "Coordinate.h"
#include <vector>

#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"

class LoadButton : 	public CustomButton
{
public:
	LoadButton(int x, int y);
	~LoadButton();

	//if this button is clicked, we read the file SavedGame and set the pieces, their coordinate, and their colour
	void handleClick(sf::Event) override;

private:
	//stores Pieces to be passed into Board::addPiecesToSquares
	std::vector<Piece*> pieces;

	//uses the coordinate, pieceSymbol, and colour (all in string type) read from the file to make a piece and then place it in the vector of Pieces
	void createPiece(const std::string, const std::string, const std::string);
};

