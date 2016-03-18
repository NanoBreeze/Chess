#include "NextButton.h"



NextButton::NextButton(int x, int y)
{
	setBackgroundColour(sf::Color::Yellow);
	setText("Next");
	setTextSize(30);
	setTextColor(sf::Color::Blue);
	setPosition(x, y);
}


NextButton::~NextButton()
{
}
