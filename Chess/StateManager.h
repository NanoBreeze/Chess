#pragma once

#include "Square.h"
#include "Turn.h"
#include <stack>

//contains information relevant to the state of the game, such as which Piece (residing on the selected Square) has been selected (if any)
class StateManager
{
public:

	//singleton for the StateManager
	static StateManager& getInstance();

	//sets the Square the user has selected.
	void setSelectedSquare(Square*);

	//return selectedPiece, which may be a pointer to a piece or a nullptr
	Square* getSelectedSquare() const;

	void removeSelectedSquare();

	std::stack<Turn> getTurns() const;


private:
	StateManager();

	//the Square that has been selected by the user. 
	Square* selectedSquare = nullptr;

	//contains the Turns from the players. Used to backtrack to a previous move
	std::stack<Turn> turns;

};

