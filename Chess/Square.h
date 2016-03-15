#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"



//Also known as a grid, eg, A1, E5, 
class Square : public sf::RectangleShape
{
public:
	Square();
	~Square();
	
	Coordinate getCoordinate() const;

	void setCoordinate(const Coordinate&);

	//A square is by default either black or white
	sf::Color getDefaultColour() const;
	void setDefaultColour(const Coordinate&);

	//returns the piece residing on this Square
	Piece* getPiece() const;

	//sets a piece to reside on this Square. Also configures that Piece's position to indicate to this Square's Coordinate, row, and column
	void setPiece(Piece*);

	//removes the current piece residing on this square
	void removePiece();

	//highlights the square. Used to indicate that it has been selected, another code must first check if such a selection is legal. The highlight has two 
	// different colours, one to show it is an empty square, the other to show that there is a piece in the square
	void highlightSelected();

	//highlights the square to show it is a legal move for another piece
	void highlightIsLegalMove();

	//unlight the square and set the display colour back to the default colour, eg, yellow to black. Used to mean this square is no longer selected
	void unHighlight();

private: 

	//contains the piece that is currently residing on this square, eg, knight, bishop, 
	Piece* piece = nullptr;

	//the board colour of the square, black or white
	sf::Color defaultColour;

	//the curent colour of the square. Usually, black or white but can be highlighted
	sf::Color displayColour;

	//the coordinate of this Square
	Coordinate coordinate;

};

