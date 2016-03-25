#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include "Turn.h"

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
	sf::Text text;
	sf::Font font;

	//stores the Turns here, in addition to StateManager, sets from StateManager
	std::stack<Turn> turns;

};

