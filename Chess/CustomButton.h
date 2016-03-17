#pragma once

#include <SFML/Graphics.hpp>

//base class for everything to do with buttons
class CustomButton : public sf::Drawable
{
public:
	CustomButton();

	~CustomButton();




protected:

	enum class FontType
	{
		Calibri, Arial
	};

	//draw buttonRectangle and text
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Represents the button's rectangular shape
	sf::RectangleShape buttonRectangle;

	virtual void setSize(sf::Vector2f(int, int)) = 0;
	virtual void setBackgroundColour(sf::Color) = 0;

	//Represents the text on the button
	sf::Text text;

	virtual void setText(sf::String) = 0;
	virtual void setTextSize(int) = 0;
	virtual void setTextColor(sf::Color) = 0;

	//Represents the font the text uses
	sf::Font font;

	virtual void setFont(FontType) = 0;
};

