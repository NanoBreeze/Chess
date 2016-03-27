#include "LoadButton.h"



LoadButton::LoadButton(int x, int y)
{
	setBackgroundColour(sf::Color::Green);
	setText("Load");
	setTextSize(30);
	setTextColor(sf::Color::Black);
	setPosition(x, y);
}


LoadButton::~LoadButton()
{
}

void LoadButton::handleClick(sf::Event event)
{
	//check if the mouseclick is on this button
	auto leftBound = buttonRectangle.getGlobalBounds().left;
	auto rightBound = buttonRectangle.getGlobalBounds().left + buttonRectangle.getGlobalBounds().width;
	auto topBound = buttonRectangle.getGlobalBounds().top;
	auto bottomBound = buttonRectangle.getGlobalBounds().top + buttonRectangle.getGlobalBounds().height;


	if ((leftBound <= event.mouseButton.x) && (event.mouseButton.x <= rightBound) && (topBound <= event.mouseButton.y) && (event.mouseButton.y <= bottomBound))
	{
		std::string line;
		std::ifstream file;
		file.open("SavedGame.txt");

		while (!file.eof())
		{
			getline(file, line);

			//stores coordinate, pieceSymbol, and color
			std::vector<std::string> delimitedValues;

			std::string delimiter = ",";

			auto start = 0U;
			auto end = line.find(delimiter);
			auto stringCoordinate = line.substr(start, end - start);

			start = end + delimiter.length();
			end = line.find(delimiter, start);
			auto pieceSymbol = line.substr(start, end - start);

			start = end + delimiter.length();
			end = line.find(delimiter, start);
			auto pieceColor = line.substr(start, end);

			//since this while loops still runs on the very last line, which contains only empty string, we don't want to create piece
			//this if statement is like an error-checker
			if (stringCoordinate != "")
			{
				createPiece(stringCoordinate, pieceSymbol, pieceColor);
			}
		}

		file.close();

		Board b = Board::getInstance();
		b.clearBoard();
		b.addPiecesToSquares(pieces);
		pieces.clear(); //if we press the Load button several times in a game, we don't want previous moves to be stored
	}

}

void LoadButton::createPiece(const std::string stringCoordinate, const std::string pieceSymbol, const std::string pieceColor)
{
	//get the coordinate
	int intCoordinate = std::stoi(stringCoordinate);
	Coordinate coordinate = static_cast<Coordinate>(intCoordinate);

	//create the correct piece
	Piece* piece = nullptr;

	if (pieceSymbol == "") { piece = new Pawn(coordinate); }
	else if (pieceSymbol == "B") { piece = new Bishop(coordinate); }
	else if (pieceSymbol == "K") { piece = new King(coordinate); }
	else if (pieceSymbol == "N") { piece = new Knight(coordinate); }
	else if (pieceSymbol == "Q") { piece = new Queen(coordinate); }
	else if (pieceSymbol == "R") { piece = new Rook(coordinate); }
	else throw std::exception("Invalid pieceSymbol");

	//set the correct colour for the piece
	if (pieceColor == "White")
	{
		piece->setIsWhite(true);
	}
	else
	{
		piece->setIsWhite(false);
	}

	pieces.push_back(piece);





}
