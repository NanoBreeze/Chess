#include "MovesDisplay.h"



MovesDisplay::MovesDisplay()
{
	font.loadFromFile("Calibri.ttf");

	assert(font.loadFromFile("Calibri.ttf") == true);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString("HELLO THERE");
	text.setPosition(200, 200);
}


MovesDisplay::~MovesDisplay()
{
}

void MovesDisplay::draw(sf::RenderTarget & target, sf::RenderStates states) const
{


	target.draw(text);

}

void MovesDisplay::setTurns(std::stack<Turn>& turns)
{
	this->turns = turns;
	if (turns.size() > 1)
	{
		text.setString("HELLO TdsfHERE");

	}
}
