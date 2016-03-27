#include "SaveButton.h"



SaveButton::SaveButton(int x, int y)
{
	setBackgroundColour(sf::Color::Green);
	setText("Save");
	setTextSize(30);
	setTextColor(sf::Color::Black);
	setPosition(x, y);
}


SaveButton::~SaveButton()
{
}

void SaveButton::handleClick(sf::Event event)
{

	//check if the mouseclick is on this button
	auto leftBound = buttonRectangle.getGlobalBounds().left;
	auto rightBound = buttonRectangle.getGlobalBounds().left + buttonRectangle.getGlobalBounds().width;
	auto topBound = buttonRectangle.getGlobalBounds().top;
	auto bottomBound = buttonRectangle.getGlobalBounds().top + buttonRectangle.getGlobalBounds().height;


	if ((leftBound <= event.mouseButton.x) && (event.mouseButton.x <= rightBound) && (topBound <= event.mouseButton.y) && (event.mouseButton.y <= bottomBound))
	{
		std::ofstream file;
		file.open("SavedGame.txt");

		if (file.is_open())
		{
			Board b = Board::getInstance();

			//get coordinates that have piece , write the coordinate (will be written as an integer), the piece type, and the piece colour
			//draw all pieces

			for (Coordinate coordinate = Coordinate::First; coordinate != Coordinate::Last; ++coordinate)
			{
				if (b[coordinate].getPiece() != nullptr)
				{
					auto piece = b[coordinate].getPiece();
					int c = static_cast<int>(piece->getCoordinate());
					std::string pieceSymbol = piece->getSymbol();
					std::string colour = piece->getIsWhite() ? "White" : "Black";
					file << c << "," << pieceSymbol << "," << colour << std::endl;
				}
			}
			file.close();
			std::cout << "File saved" << std::endl;
		}
	}
}
