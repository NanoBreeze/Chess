#include "SaveButton.h"



SaveButton::SaveButton(int x, int y)
{
	setBackgroundColour(sf::Color::Green);
	setText("Save");
	setTextSize(30);
	setTextColor(sf::Color::Black);
	setPosition(x, y);
}


SaveButton::~SaveButton()
{
}

void SaveButton::handleClick()
{
}
