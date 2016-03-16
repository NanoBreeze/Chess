#include "Bishop.h"
#include "Board.h"

//set coordinate and size
Bishop::Bishop(Coordinate coordinate) 
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	setSize(sf::Vector2f(20, 20));
}

//problem, in the moveableSquares, there are duplications of the current square the bishop is in
std::vector<Coordinate> Bishop::computeMoves()
{
	//first clear past movablePositions
	clearMoves();

	auto c = coordinate;

	//compute top right squares, stop if row is over 7 or column is over 7
	while(c != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c == coordinate) { c = CoordinateHelper::getCoordinateUpRight(c); continue; }

		if (addPartOne(c)) { break; }
		//2
		else
		{
			moves.push_back(c);
			c = CoordinateHelper::getCoordinateUpRight(c);
		}
	}


	auto c2 = coordinate;

	//compute bottom left squares, stop if row is under 0 or column is under 0
	while (c2 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c2 == coordinate) { c2 = CoordinateHelper::getCoordinateDownLeft(c2); continue; }

		if (addPartOne(c2)) { break; }
		else
		{
			moves.push_back(c2);
			c2 = CoordinateHelper::getCoordinateDownLeft(c2);
		}

	}


	//compute top left squares, stop if row is over 7 or column is under 0
	auto c3 = coordinate;

	while (c3 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c3 == coordinate) { c3 = CoordinateHelper::getCoordinateUpLeft(c3); continue; }

		if (addPartOne(c3)) { break; }
		else
		{
			moves.push_back(c3);
			c3 = CoordinateHelper::getCoordinateUpLeft(c3);
		}
	}
	

	//compute bottom right squares, stop if row is over 7 or column is under 0
	auto c4 = coordinate;

	while (c4 != Coordinate::Invalid)
	{
		//we will not add the Bishop's current position to moves
		if (c4 == coordinate) { c4 = CoordinateHelper::getCoordinateDownRight(c4); continue; }

		if (addPartOne(c4)) { break; }
		else
		{
			moves.push_back(c4);
			c4 = CoordinateHelper::getCoordinateDownRight(c4);
		}
	}

	return moves;
}

bool Bishop::addPartOne(const Coordinate& c)
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
