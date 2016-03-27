#include <SFML/Graphics.hpp>
#include <iostream>

#include "Square.h"
#include "Game.h"
#include "Coordinate.h"
#include "Board.h"
#include "CustomButton.h"
#include "PreviousButton.h"
#include "NextButton.h"
#include "SaveButton.h"

#include "MovesDisplay.h"

#include <fstream>

int main()
{

	//we do not allow resizing right now because that will conflict with out hard-coded numbers for associating mouse position to Square 
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	
	Game game;


	while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x <= 400) //400px is the width of the chessboard, if inside, select piece, if beyond width, then we're doing another operation
				{
					game.delegateClick(event.mouseButton.x, event.mouseButton.y);
				}

				//pass event to save button to check if it handles this event, since it definitely can't be a simple click to move piece
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x > 400)
				{
					game.stateManager.getSaveButton()->handleClick(event);
					game.stateManager.getLoadButton()->handleClick(event);
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
					//game.board[coordinate].getPiece()->setFillColor(sf::Color::Red);
					auto piece = game.board[coordinate].getPiece();
					window.draw(*piece);
				}
			}


			window.draw(game.stateManager.getMovesDisplay());
			window.draw(*game.stateManager.getSaveButton());
			window.draw(*game.stateManager.getLoadButton());
			
		window.display();
	}

	return 0;
}