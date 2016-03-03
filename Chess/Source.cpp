#include <SFML/Graphics.hpp>
#include <iostream>

#include "Square.h"
#include "Chessboard.h"


int main()
{
	
	
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	Chessboard chessboard;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type==sf::Event::MouseButtonPressed)
			{
				chessboard.delegateClick(event.mouseButton.x, event.mouseButton.y);
			}
		}

		window.clear(sf::Color::Yellow);

		//draw chessboard
		for (int row = 0; row < 8; row++)
		{
			for (int column = 0; column < 8; column++)
			{
				window.draw(chessboard.squares[row][column]);
			}
		}

		//draw the bishop
		chessboard.squares[3][4].getBishop()->setFillColor(sf::Color::Green);
		auto j = chessboard.squares[3][4].getBishop();
		window.draw(*j);
		window.display();
	}

	return 0;
}