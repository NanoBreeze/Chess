#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>

//base class for everything to do with buttons. The text is always centered, and has 1/5 the text size's padding
class CustomButton : public sf::Drawable
{
public:
	//automatically calls setPosition
	CustomButton();

	~CustomButton();

	//sets the position of the button
	void setPosition(int x, int y);




protected:
	//draw buttonRectangle and text
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Represents the button's rectangular shape
	sf::RectangleShape buttonRectangle;

	 void setBackgroundColour(sf::Color);

	//Represents the text on the button
	sf::Text text;

	 void setTextSize(int);
	 void setTextColor(sf::Color);
	 void setText(sf::String);

	//Represents the font the text uses
	sf::Font font;

	 void setToCalibriFont();

private:
	 void setBackgroundRectanglePosition(int x, int y);
	 void setBackgroundRectangleSize(int width, int length);
	 void setTextPosition(int x, int y);

};

