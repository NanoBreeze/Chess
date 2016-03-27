#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include "Turn.h"
#include <string.h>
#include "CustomButton.h"
#include "NextButton.h"
#include "PreviousButton.h"

//This is a visual display that displays every move that has been made, it itself doesn't store the moves
class MovesDisplay : public sf::Drawable
{
public:
	MovesDisplay();
	~MovesDisplay();

	//draw the list of moves, and text
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//gets a stack of Turns and visually displays each one, requires position of each, and the move that has been made
	void setTurns(std::stack<Turn>& turns);


private:

	CustomButton* nextButton = new NextButton(500, 10);
	CustomButton* previousButton = new PreviousButton(550, 10);


	//converts the coordinate to return its string representation, eg, A3 would becom
	std::string convertCoordinateToString(const Coordinate&);

	sf::Text text;
	sf::Font font;

	//stores the Turns here, in addition to StateManager, sets from StateManager
	std::stack<Turn> turns;

	//stores the text associated with each turn, each text indicates the piece that moved, may consider using a stack instead 
	std::vector<sf::Text> texts;

};

