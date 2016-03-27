#pragma once

#include "Square.h"
#include "Turn.h"
#include "MovesDisplay.h"
#include <stack>
#include "CustomButton.h"
#include "SaveButton.h"
#include "LoadButton.h"

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

	MovesDisplay& getMovesDisplay();

	CustomButton* getSaveButton();

	CustomButton* getLoadButton();

	std::stack<Turn>& getTurns() ;


private:
	StateManager();

	//the Square that has been selected by the user. 
	Square* selectedSquare = nullptr;

	//contains the Turns from the players. Used to backtrack to a previous move
	std::stack<Turn> turns;

	//a sf::Drawable that contains the drawing dettails for drawing
	MovesDisplay movesDisplay;

	//pressing this button saves the current game
	CustomButton* saveButton = new SaveButton(500, 300);

	//pressing this button loads the saved game by parsing its files
	CustomButton* loadButton = new LoadButton(500, 350);

};

