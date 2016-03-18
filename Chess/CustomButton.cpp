#include "CustomButton.h"

#include <iostream>


//mandatory methods: setBackgroundColor, setTextSize, setTextColor, setText, must call setPosition
CustomButton::CustomButton()
{	

	setToCalibriFont();
}


CustomButton::~CustomButton()
{
}

void CustomButton::setText(sf::String t)
{
	text.setString(t);
}

//assume the text and all things related to text have already been set
void CustomButton::setPosition(int x, int y)
{
	setBackgroundRectanglePosition(x, y);

	auto textHeight = text.getLocalBounds().height;
	auto textWidth = text.getLocalBounds().width;


	auto buttonRectangleWidth = textWidth / 4 + textWidth + textWidth / 4;
	auto buttonRectangleHeight = textHeight /4  + textHeight + textHeight / 4;


	//set the rectangle to be large enough to contain padding
	setBackgroundRectangleSize(buttonRectangleWidth, buttonRectangleHeight);

	//centering the text is more complicated, we consider the text's x and y offsets

	auto yOffset = (buttonRectangleHeight - textHeight) / 2;
	auto xOffset = (buttonRectangleWidth - textWidth) / 2;

	setTextPosition(x + xOffset, y - yOffset);
}

void CustomButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(buttonRectangle);
	target.draw(text);
}

void CustomButton::setBackgroundColour(sf::Color colour)
{
	buttonRectangle.setFillColor(colour);
}



void CustomButton::setTextSize(int size)
{
	text.setCharacterSize(size);
}

void CustomButton::setTextColor(sf::Color colour)
{
	text.setColor(colour);
}



void CustomButton::setToCalibriFont()
{
	
	font.loadFromFile("Calibri.ttf");

	assert(font.loadFromFile("Calibri.ttf") == true);
	text.setFont(font);

}

void CustomButton::setBackgroundRectanglePosition(int x, int y)
{
	buttonRectangle.setPosition(sf::Vector2f(x, y));
}

void CustomButton::setBackgroundRectangleSize(int width, int length)
{
	buttonRectangle.setSize(sf::Vector2f(width, length));
}

void CustomButton::setTextPosition(int x, int y)
{
	text.setPosition(sf::Vector2f(x, y));
}


