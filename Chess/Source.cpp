#include <SFML/Graphics.hpp>
#include <iostream>

#include "Square.h"
#include "Chessboard.h"


int main()
{
	
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

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
				std::cout << "Mouse pressed. The x coordinate is:" << event.mouseButton.x << " and the y coordinate is:" << event.mouseButton.y << "\n";
				if (event.mouseButton.x < 300)
				{
					chessboard.squares[0][1].handleClick();
				}
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
		window.display();
	}

	return 0;
}