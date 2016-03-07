#pragma once

#include "Square.h"

//contains information relevant to the state of the game, such as which Piece (residing on the selected Square) has been selected (if any)
class StateManager
{
public:


	//sets selectedPiece. Intended to be set to the piece currently residing on the Square
	void setSelectedSquare(Square*);

	//return selectedPiece, which may be a pointer to a piece or a nullptr
	Square* getSelectedSquare() const;

	void removeSelectedSquare();
	Square* selectedSquare = nullptr;

	StateManager();

private:

	//the that has been selected by the user. If the Square contains a piece, we set the piece here. 
	//Then the next click is where the Piece moves to. If the square doesn't contain a piece, then the next click is,
	//well the next click. Piece doesn't move and repeate
};

