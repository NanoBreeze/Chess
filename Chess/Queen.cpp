#include "Queen.h"
#include "Board.h"


Queen::Queen(Coordinate coordinate) 
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	setSize(sf::Vector2f(20, 20));
}


std::vector<Coordinate> Queen::computeMoves()
{
	//first clear past movablePositions
	clearMoves();

	//This is a conglomeration of Rook's and Bishop's moves

/* ================== ROOK ====================*/


	//compute left Squares
	auto c = coordinate;

	while (c != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c == coordinate) { c = CoordinateHelper::getCoordinateLeft(c); continue; }

		if (addPartOne(c)) { break; }
		//2
		else
		{
			moves.push_back(c);
			c = CoordinateHelper::getCoordinateLeft(c);
		}
	}

	//compute right Squares
	auto c2 = coordinate;

	while (c2 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c2 == coordinate) { c2 = CoordinateHelper::getCoordinateRight(c2); continue; }

		if (addPartOne(c2)) { break; }
		//2
		else
		{
			moves.push_back(c2);
			c2 = CoordinateHelper::getCoordinateRight(c2);
		}
	}



	//compute top Squares
	auto c3 = coordinate;


	while (c3 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c3 == coordinate) { c3 = CoordinateHelper::getCoordinateUp(c3); continue; }

		if (addPartOne(c3)) { break; }
		//2
		else
		{
			moves.push_back(c3);
			c3 = CoordinateHelper::getCoordinateUp(c3);
		}
	}


	//compute bottom Squares
	auto c4 = coordinate;


	while (c4 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c4 == coordinate) { c4 = CoordinateHelper::getCoordinateDown(c4); continue; }

		if (addPartOne(c4)) { break; }
		//2
		else
		{
			moves.push_back(c4);
			c4 = CoordinateHelper::getCoordinateDown(c4);
		}
	}


	/* ====================== BISHOP ===================== */



	//compute top right squares, stop if row is over 7 or column is over 7
	auto c5 = coordinate;

	while (c5 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c5 == coordinate) { c5 = CoordinateHelper::getCoordinateUpRight(c5); continue; }

		if (addPartOne(c5)) { break; }
		//2
		else
		{
			moves.push_back(c5);
			c5 = CoordinateHelper::getCoordinateUpRight(c5);
		}
	}



	//compute top left squares, stop if row is over 7 or column is under 0
	auto c6 = coordinate;

	while (c6 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c6 == coordinate) { c6 = CoordinateHelper::getCoordinateUpLeft(c6); continue; }

		if (addPartOne(c6)) { break; }
		else
		{
			moves.push_back(c6);
			c6 = CoordinateHelper::getCoordinateUpLeft(c6);
		}
	}

	//compute bottom right squares, stop if row is under 0 or column is over 7
	auto c7 = coordinate;

	while (c7 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c7 == coordinate) { c7 = CoordinateHelper::getCoordinateDownRight(c7); continue; }

		if (addPartOne(c7)) { break; }
		else
		{
			moves.push_back(c7);
			c7 = CoordinateHelper::getCoordinateDownRight(c7);
		}
	}

	//compute bottom left squares
	auto c8 = coordinate;

	while (c8 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c8 == coordinate) { c8 = CoordinateHelper::getCoordinateDownLeft(c8); continue; }

		if (addPartOne(c8)) { break; }
		else
		{
			moves.push_back(c8);
			c8 = CoordinateHelper::getCoordinateDownLeft(c8);
		}

	}

	return moves;

}

bool Queen::addPartOne(const Coordinate& c)
{
	//1
	if (board[c].getPiece() != nullptr)
	{
		//a)
		if (board[c].getPiece()->getIsWhite() == this->isWhite)
		{
			return true;
		}
		//b)
		else
		{
			moves.push_back(c);
			return true;
		}
	}
	return false;
}
