#pragma once

#include <SFML/Graphics.hpp>
#include "Coordinate.h"
#include <vector>
#include "Hey.h"


//The bishop piece, consider using abstraction
class Bishop : public sf::RectangleShape
{
public:



	Bishop();

	Coordinate getCoordinate() const;

	//sets the bishop to the specified coordinate and also sets the bishops x-y position, along with the squares it can move to
	void setCoordinate(Coordinate coordinate);

	//returns the vector of movable squares
	std::vector<Coordinate> getMovableSquares() const;

	

private : 
	Coordinate coordinate;
	
	//contains the coordinates this bishop can move to. This field frequently changes
	std::vector<Coordinate> movableSquares;

	//called every time the bishop moves to a new square or is newly made because that's when its movable squares change.
	void computeMovableSquares();

	//returns bishop's row from its coordinate
	int getRow() const;

	//returns the bishop's column from its coordinates
	int getColumn() const;

	//computes the coordinate from the row and column
	Coordinate computeCoordinate(int, int);
};


