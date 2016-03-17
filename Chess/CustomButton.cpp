#include "CustomButton.h"

#include <iostream>

CustomButton::CustomButton()
{	
	//each square is 50px by 50px
	m_button.setSize(sf::Vector2f(50, 50));
	m_button.setFillColor(sf::Color::Yellow);



	if (!font.loadFromFile("Calibri.ttf"))
		std::cout << "Not loaded";

	text.setString("Hello world!");
	text.setFont(font);
	text.setOrigin(20, 20);
	text.setColor()
	text.setCharacterSize(30);
	


}


CustomButton::~CustomButton()
{
}

void CustomButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{


	

	target.draw(m_button);
	target.draw(text);
}
