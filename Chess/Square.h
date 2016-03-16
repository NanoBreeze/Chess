#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"



class Square : public sf::RectangleShape
{
public:
	//sets the physical size of the Square (it is a sf::RectangleShape after all)
	Square();

	//removes piece
	~Square();
	
	//returns coordinate
	Coordinate getCoordinate() const;

	//assigns the Square a coordinate and sets its defaultColor (black or white) to correspond with that Coordinate
	void setCoordinateAndDefaultColour(const Coordinate&);

	//============ AFFECTING THE SQUARE'S PIECE ================

	//returns the piece residing on this Square
	Piece* getPiece() const;

	//sets a piece to reside on this Square. Also configures that Piece's position to indicate to this Square's Coordinate, row, and column
	void setPiece(Piece*);

	//removes the current piece residing on this square
	void removePiece();

	//=========== CHANGING THE VISUAL COLOUR OF THE SQUARE TO INDICATE STATE ===============

	//changes the Square's colour to Yellow to show that it is selected
	void showSelectedColour();

	//changes the Square's colour to Cyan to show that this Square is a valid Square for the selected Piece to move to
	void showLegalMoveColour();

	//changes the Square's colour to its default colour (black, white), thus, Square is not selected or a legal move
	void showDefaultColour();


private: 

	//contains the piece that is currently residing on this square, eg, knight, bishop, 
	Piece* piece = nullptr;

	//the original colour of the square, black or white, assigned by its Coordinate
	sf::Color defaultColour;

	//the coordinate of this Square
	Coordinate coordinate;
};

