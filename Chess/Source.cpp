#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

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



int main()
{


	//we do not allow resizing right now because that will conflict with out hard-coded numbers for associating mouse position to Square 
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!", sf::Style::Titlebar | sf::Style::Close);

	std::cout << "Welcome to TCP::Chess! (in development)" << std::endl <<
		"TCP::Chess is a human vs human chess game. It load and save games, record moves, and be played on a single machine or different machines." << std::endl <<
		"Type 'solo' to play on single machine, 'host' to become host, or an ip address to handshake with the waiting host." << std::endl <<
		"The ip address of the localhost is 127.0.0.1. This program uses port 45000";

	sf::TcpSocket socket;
	socket.setBlocking(false);
	std::string consoleInput;
	std::cin >> consoleInput;

	//indicates if whether we would be using TcpSocket or not
	bool solo;
	Game game;

	if (consoleInput == "solo")
	{
		solo = true;
	}
	else
	{
		solo = false;
		if (consoleInput == "host")
		{
			sf::TcpListener listener;
			listener.listen(45000);
			std::cout << "Waiting for connection..." << std::endl;
			if (listener.accept(socket) != sf::Socket::Done)
			{
				std::cout << "Socket is unavailable for listening";
			}
			else
			{
				std::cout << "Ready to listen";
			}

		}
		else
		{
			std::cout << "Trying to connect..." << std::endl;
			if (socket.connect(consoleInput, 45000, sf::seconds(30)) != sf::Socket::Done)
			{
				std::cout << "Couldn't connect for some reason";
			}
			else
			{
				std::cout << "Connection made!";

				/*	const int msgSize = 100;
					char message[msgSize] = "Hello!";

					if (socket.send(message, msgSize) != sf::Socket::Done)
					{
						std::cout << "The message couldn't be sent";
					}
					else
					{
						std::cout << "Message sent";
					}*/
			}
		}
	}

	while (window.isOpen())
	{
		const std::size_t size = 5;
		char data[size];
		std::size_t readSize;

		if (socket.receive(data, size, readSize) == sf::Socket::Done)
		{
			std::cout << "The received data is: " << data << std::endl;

			//we received the coordinate of a piece's from and to positions.
			//we call a game's function to find the piece that is on the from and now place it on the to
			game.delegateReceivedMove(data, size);
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.x <= 400) //400px is the width of the chessboard, if inside, select piece, if beyond width, then we're doing another operation
			{
				game.delegateClick(event.mouseButton.x, event.mouseButton.y, socket, solo);
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