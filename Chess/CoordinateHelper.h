#pragma once

#include "Coordinate.h"
#include <assert.h>

class CoordinateHelper
{
public:
	//====All these getCoordinateDirection would throw exception if invalid value occurs, these are intended to be used by Pieces when they compute movable coordinates
	static Coordinate getCoordinateUp(Coordinate) ;

	static Coordinate getCoordinateDown(Coordinate) ;

	static Coordinate getCoordinateLeft(Coordinate) ;

	static Coordinate getCoordinateRight(Coordinate) ;

	static Coordinate getCoordinateUpRight(Coordinate) ;

	static Coordinate getCoordinateUpLeft(Coordinate);

	static Coordinate getCoordinateDownRight(Coordinate);

	static Coordinate getCoordinateDownLeft(Coordinate);

	//===All these return the most (up) coordinate with the starting point of the current coordinate. All these Coordinate returned may be self-inclusive, same as current
	static Coordinate getMostUpCoordinate(Coordinate);

	static Coordinate getMostDownCoordinate(Coordinate);

	static Coordinate getMostLeftCoordinate(Coordinate);

	static Coordinate getMostRightCoordinate(Coordinate);

	static Coordinate getMostUpRightCoordinate(Coordinate);

	static Coordinate getMostUpLeftCoordinate(Coordinate);

	static 	Coordinate getMostDownRightCoordinate(Coordinate);

	static 	Coordinate getMostDownLeftCoordinate(Coordinate);

	//======================== KNIGHT MOVES ========================//

	static Coordinate TwoUpOneRight(Coordinate) ;

	static 	Coordinate TwoUpOneLeft(Coordinate);

	static 	Coordinate OneUpTwoRight(Coordinate) ;

	static 	Coordinate OneUpTwoLeft(Coordinate) ;

	static 	Coordinate TwoDownOneRight(Coordinate) ;

	static 	Coordinate TwoDownOneLeft(Coordinate) ;

	static 	Coordinate OneDownTwoRight(Coordinate) ;

	static 	Coordinate OneDownTwoLeft(Coordinate) ;

private:
	//returns a Coordinate::Invalide if the row or column is out of range;
	static bool checkIfInvalidCoordinate(int, int);

	static bool checkIfInvalidCoordinate(int);
	
};

