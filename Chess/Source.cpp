#include <SFML/Graphics.hpp>
#include <iostream>

#include "Square.h"
#include "Game.h"
#include "Coordinate.h"
#include "Board.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	Game game;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				game.delegateClick(event.mouseButton.x, event.mouseButton.y);
			}
		}

		window.clear(sf::Color::Yellow);

		//draw chessboard
		for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
		{
			window.draw(game.board[coordinate]);
		}

		//draw all pieces
		for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
		{
			if (game.board[coordinate].getPiece() != nullptr)
			{
				game.board[coordinate].getPiece()->setFillColor(sf::Color::Red);
				auto j = game.board[coordinate].getPiece();
				window.draw(*j);
			}
		}

		window.display();
	}

	return 0;
}