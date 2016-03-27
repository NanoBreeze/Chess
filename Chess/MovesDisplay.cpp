#include "MovesDisplay.h"



MovesDisplay::MovesDisplay()
{
	font.loadFromFile("Calibri.ttf");

	assert(font.loadFromFile("Calibri.ttf") == true);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString("HELLO THERE");
	text.setPosition(200, 200);
}


MovesDisplay::~MovesDisplay()
{
}

void MovesDisplay::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto text : texts)
	{
		target.draw(text);
	}
	target.draw(*nextButton);
	target.draw(*previousButton);

}

void MovesDisplay::setTurns(std::stack<Turn>& turns)
{
	//since this function is called every frame, we want to make sure it is called appropriately and would add new turn only when the count is 
	//difference from he current count

	if (turns.size() != this->turns.size())
	{
		this->turns = turns;

		//change all previous move's colour to white. Only this move shall be highlighted as blue
		for (auto& text : texts)
		{
			text.setColor(sf::Color::White);
		}

		sf::Text t;
		font.loadFromFile("Calibri.ttf");

		assert(font.loadFromFile("Calibri.ttf") == true);
		t.setFont(font);
		t.setCharacterSize(15);

		std::string pieceSymbol = this->turns.top().getPieceMoved()->getSymbol();
		std::string isCaptured = (this->turns.top().getCapturedPiece() == nullptr) ? "" : "x";
		std::string toCoordinate = convertCoordinateToString(this->turns.top().getToCoordinate());

		t.setString(pieceSymbol+isCaptured+toCoordinate);

		//the position of the sf::Text depends on which text it is, look at chart below

		int xCoordinate;
		int yCoordinate;

		//determine x coordinate
		if ((this->turns.size() - 1) % 2 == 0)
		{
			xCoordinate = 410;
		}
		else { xCoordinate = 460; }

		//determine y coordinate
		int multiFactor = (this->turns.size() - 1) / 2;
		yCoordinate = 10 + multiFactor * 30;

		t.setPosition(xCoordinate, yCoordinate);
		t.setColor(sf::Color::Blue);
		texts.push_back(t);
	}

	/*
	(410,10) 0, (460,10) 1
	(410,60) 2, (460,60) 3
	(410,110) 4, (460,110) 5
	(460, 160) 6, (460,160) 7
	*/

}

std::string MovesDisplay::convertCoordinateToString(const Coordinate& c)
{
	/*
	A1, B1, C1, D1, E1, F1, G1, H1,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A8, B8, C8, D8, E8, F8, G8, H8
	*/
	switch (c)
	{
	case Coordinate::A1:
		return "a1";
	case Coordinate::A2:
		return "a2";
	case Coordinate::A3:
		return "a3";
	case Coordinate::A4:
		return "a4";
	case Coordinate::A5:
		return "a5";
	case Coordinate::A6:
		return "a6";
	case Coordinate::A7:
		return "a7";
	case Coordinate::A8:
		return "a8";

	case Coordinate::B1:
		return "b1";
	case Coordinate::B2:
		return "b2";
	case Coordinate::B3:
		return "b3";
	case Coordinate::B4:
		return "b4";
	case Coordinate::B5:
		return "b5";
	case Coordinate::B6:
		return "b6";
	case Coordinate::B7:
		return "b7";
	case Coordinate::B8:
		return "b8";

	case Coordinate::C1:
		return "c1";
	case Coordinate::C2:
		return "c2";
	case Coordinate::C3:
		return "c3";
	case Coordinate::C4:
		return "c4";
	case Coordinate::C5:
		return "c5";
	case Coordinate::C6:
		return "c6";
	case Coordinate::C7:
		return "c7";
	case Coordinate::C8:
		return "c8";

	case Coordinate::D1:
		return "d1";
	case Coordinate::D2:
		return "d2";
	case Coordinate::D3:
		return "d3";
	case Coordinate::D4:
		return "d4";
	case Coordinate::D5:
		return "d5";
	case Coordinate::D6:
		return "d6";
	case Coordinate::D7:
		return "d7";
	case Coordinate::D8:
		return "d8";

	case Coordinate::E1:
		return "e1";
	case Coordinate::E2:
		return "e2";
	case Coordinate::E3:
		return "e3";
	case Coordinate::E4:
		return "e4";
	case Coordinate::E5:
		return "e5";
	case Coordinate::E6:
		return "e6";
	case Coordinate::E7:
		return "e7";
	case Coordinate::E8:
		return "e8";

	case Coordinate::F1:
		return "f1";
	case Coordinate::F2:
		return "f2";
	case Coordinate::F3:
		return "f3";
	case Coordinate::F4:
		return "f4";
	case Coordinate::F5:
		return "f5";
	case Coordinate::F6:
		return "f6";
	case Coordinate::F7:
		return "f7";
	case Coordinate::F8:
		return "f8";

	case Coordinate::G1:
		return "g1";
	case Coordinate::G2:
		return "g2";
	case Coordinate::G3:
		return "g3";
	case Coordinate::G4:
		return "g4";
	case Coordinate::G5:
		return "g5";
	case Coordinate::G6:
		return "g6";
	case Coordinate::G7:
		return "g7";
	case Coordinate::G8:
		return "g8";

	case Coordinate::H1:
		return "h1";
	case Coordinate::H2:
		return "h2";
	case Coordinate::H3:
		return "h3";
	case Coordinate::H4:
		return "h4";
	case Coordinate::H5:
		return "h5";
	case Coordinate::H6:
		return "h6";
	case Coordinate::H7:
		return "h7";
	case Coordinate::H8:
		return "h8";
	}
}
