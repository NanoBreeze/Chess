#pragma once

#include "Coordinate.h"
#include <assert.h>

class CoordinateHelper
{
public:
	//====All these getCoordinateDirection would throw exception if invalid value occurs, these are intended to be used by Pieces when they compute movable coordinates
	static Coordinate getCoordinateUp(const Coordinate&) ;

	static Coordinate getCoordinateDown(const Coordinate&) ;

	static Coordinate getCoordinateLeft(const Coordinate&) ;

	static Coordinate getCoordinateRight(const Coordinate&) ;

	static Coordinate getCoordinateUpRight(const Coordinate&) ;

	static Coordinate getCoordinateUpLeft(const Coordinate&);

	static Coordinate getCoordinateDownRight(const Coordinate&);

	static Coordinate getCoordinateDownLeft(const Coordinate&);

	//===All these return the most (up) coordinate with the starting point of the current coordinate. All these Coordinate returned may be self-inclusive, same as current
	static Coordinate getMostUpCoordinate(const Coordinate&);

	static Coordinate getMostDownCoordinate(const Coordinate&);

	static Coordinate getMostLeftCoordinate(const Coordinate&);

	static Coordinate getMostRightCoordinate(const Coordinate&);

	static Coordinate getMostUpRightCoordinate(const Coordinate&);

	static Coordinate getMostUpLeftCoordinate(const Coordinate&);

	static 	Coordinate getMostDownRightCoordinate(const Coordinate&);

	static 	Coordinate getMostDownLeftCoordinate(const Coordinate&);

	//======================== KNIGHT MOVES ========================//

	static Coordinate TwoUpOneRight(const Coordinate&) ;

	static 	Coordinate TwoUpOneLeft(const Coordinate&);

	static 	Coordinate OneUpTwoRight(const Coordinate&) ;

	static 	Coordinate OneUpTwoLeft(const Coordinate&) ;

	static 	Coordinate TwoDownOneRight(const Coordinate&) ;

	static 	Coordinate TwoDownOneLeft(const Coordinate&) ;

	static 	Coordinate OneDownTwoRight(const Coordinate&) ;

	static 	Coordinate OneDownTwoLeft(const Coordinate&) ;

private:
	//returns a Coordinate::Invalide if the row or column is out of range;
	static bool checkIfInvalidCoordinate(const int&, const int&);

	static bool checkIfInvalidCoordinate(const int&);
	
};

