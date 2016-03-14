#include "Square.h"

Square::Square()
{
	//each square is 50px by 50px
	setSize(sf::Vector2f(50, 50));
}


Coordinate Square::getCoordinate() const
{
	return coordinate;
}

void Square::setCoordinate(const Coordinate coordinate)
{
	this->coordinate = coordinate;
}

sf::Color Square::getDefaultColour() const
{
	return defaultColour;
}

void Square::setDefaultColour(const Coordinate coordinate)
{
	switch (coordinate)
	{
	case Coordinate::A1:
	case Coordinate::A3:
	case Coordinate::A5:
	case Coordinate::A7:

	case Coordinate::B2:
	case Coordinate::B4:
	case Coordinate::B6:
	case Coordinate::B8:

	case Coordinate::C1:
	case Coordinate::C3:
	case Coordinate::C5:
	case Coordinate::C7:

	case Coordinate::D2:
	case Coordinate::D4:
	case Coordinate::D6:
	case Coordinate::D8:

	case Coordinate::E1:
	case Coordinate::E3:
	case Coordinate::E5:
	case Coordinate::E7:

	case Coordinate::F2:
	case Coordinate::F4:
	case Coordinate::F6:
	case Coordinate::F8:

	case Coordinate::G1:
	case Coordinate::G3:
	case Coordinate::G5:
	case Coordinate::G7:

	case Coordinate::H2:
	case Coordinate::H4:
	case Coordinate::H6:
	case Coordinate::H8:

		defaultColour = sf::Color::Black;
		displayColour = defaultColour;
		setFillColor(displayColour);
		break;

	case Coordinate::A2:
	case Coordinate::A4:
	case Coordinate::A6:
	case Coordinate::A8:

	case Coordinate::B1:
	case Coordinate::B3:
	case Coordinate::B5:
	case Coordinate::B7:

	case Coordinate::C2:
	case Coordinate::C4:
	case Coordinate::C6:
	case Coordinate::C8:

	case Coordinate::D1:
	case Coordinate::D3:
	case Coordinate::D5:
	case Coordinate::D7:

	case Coordinate::E2:
	case Coordinate::E4:
	case Coordinate::E6:
	case Coordinate::E8:

	case Coordinate::F1:
	case Coordinate::F3:
	case Coordinate::F5:
	case Coordinate::F7:

	case Coordinate::G2:
	case Coordinate::G4:
	case Coordinate::G6:
	case Coordinate::G8:

	case Coordinate::H1:
	case Coordinate::H3:
	case Coordinate::H5:
	case Coordinate::H7:

		defaultColour = sf::Color::White;
		displayColour = defaultColour;
		setFillColor(displayColour);
		break;
	default:
		throw std::exception("In Square.cpp, setDefaultColour, default case, this should not have occurred.");
	}
}

Piece* Square::getPiece() const
{
	return piece;
}

void Square::setPiece(Piece* piece)
{
	 this->piece = piece;
}

void Square::removePiece()
{
	piece = nullptr;
}

void Square::highlightSelected()
{
		displayColour = sf::Color::Yellow;
		setFillColor(displayColour);
}

void Square::highlightIsLegalMove()
{
	displayColour = sf::Color::Cyan;
	setFillColor(displayColour);
}

void Square::unHighlight()
{
	displayColour = defaultColour;
	setFillColor(displayColour);
}


