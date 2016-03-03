#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"
#include "Bishop.h"


//Also known as a grid, eg, A1, E5, 
class Square : public sf::RectangleShape
{
public:
	Square();

	//A square's colour can change when it is clicked on to denote it has been selected 
	//returns the square's coordinate, eg, A1, E5
	Coordinate getCoordinate() const;
	void setCoordinate(const Coordinate);

	//A square is by default either black or white
	sf::Color getDefaultColour() const;
	void setDefaultColour(const Coordinate);

	//returns the piece residing on this Square
	Bishop* getBishop() const;

	//sets a piece to reside on this Square
	void setBishop(Bishop*);

	//removes the current piece residing on this square
	void removePiece();

	//temporary method, to check if it's possible to handle a click event
	void handleClick() { std::cout << "This piece has been clicked. Its coordinates are:" << ((int)coordinate) << "\n"; }

	//highlights the square. Used to indicate that it has been selected, another code must first check if such a selection is legal.
	void highlightSelected();

	//highlights the square to show it is a legal move for another piece
	void highlightIsLegalMove();

	//unlight the square and set the display colour back to the default colour, eg, yellow to black. Used to mean this square is no longer selected
	void unHighlight();

private: 

	//contains the piece that is currently residing on this square, eg, knight, bishop, 
	Bishop* bishop = nullptr;

	//the board colour of the square, black or white
	sf::Color defaultColour;

	//the curent colour of the square. Usually, black or white but can be highlighted
	sf::Color displayColour;

	//the square's coordinate, eg, A1, E5
	Coordinate coordinate;

};

