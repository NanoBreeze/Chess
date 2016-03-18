#include "PreviousButton.h"



PreviousButton::PreviousButton(int x, int y)
{
	setBackgroundColour(sf::Color::Yellow);
	setText("Previous");
	setTextSize(30);
	setTextColor(sf::Color::Blue);
	setPosition(x, y);
}


PreviousButton::~PreviousButton()
{
}
