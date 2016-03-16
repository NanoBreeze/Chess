#include "King.h"
#include "Board.h"




King::King(Coordinate coordinate)
{
	this->coordinate = coordinate;

	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	sf::RectangleShape::setPosition(sf::Vector2f(column * 50, 350 - row * 50));

	setSize(sf::Vector2f(20, 20));
}

std::vector<Coordinate> King::computeMoves()
{
	//first clear past movablePositions
	clearMoves();

	//similar to Queens, but less

	//top
	auto OneUp = CoordinateHelper::getCoordinateUp(coordinate);
	if (CoordinateHelper::getMostUpCoordinate(coordinate) != OneUp || OneUp != Coordinate::Invalid)
	{
		addMove(OneUp);
	}

	//bottom
	auto OneDown = CoordinateHelper::getCoordinateDown(coordinate);
	if (CoordinateHelper::getMostDownCoordinate(coordinate) != OneDown || OneDown != Coordinate::Invalid)
	{
		addMove(OneDown);
	}
	

	//left
	auto OneLeft = CoordinateHelper::getCoordinateLeft(coordinate);
	if (CoordinateHelper::getMostLeftCoordinate(coordinate) != OneLeft || OneLeft != Coordinate::Invalid)
	{
		addMove(OneLeft);
	}


	//right
	auto OneRight = CoordinateHelper::getCoordinateRight(coordinate);
	if (CoordinateHelper::getMostRightCoordinate(coordinate) != OneRight || OneRight != Coordinate::Invalid)
	{
		addMove(OneRight);
	}

	//top-left
	auto OneUpLeft = CoordinateHelper::getCoordinateUpLeft(coordinate);
	if (CoordinateHelper::getMostUpLeftCoordinate(coordinate) != OneUpLeft || OneUpLeft != Coordinate::Invalid)
	{
		addMove(OneUpLeft);
	}
	

	//top-right
	auto OneUpRight = CoordinateHelper::getCoordinateUpRight(coordinate);
	if (CoordinateHelper::getMostUpRightCoordinate(coordinate) != OneUpRight || OneUpRight != Coordinate::Invalid)
	{
		addMove(OneUpRight);
	}
	

	//bottom-left
	auto OneDownLeft = CoordinateHelper::getCoordinateDownLeft(coordinate);
	if (CoordinateHelper::getMostDownLeftCoordinate(coordinate) != OneDownLeft || OneDownLeft != Coordinate::Invalid)
	{
		addMove(OneDownLeft);
	}
	

	//bottom-right
	auto OneDownRight = CoordinateHelper::getCoordinateDownRight(coordinate);
	if (CoordinateHelper::getMostDownRightCoordinate(coordinate) != OneDownRight || OneDownRight != Coordinate::Invalid)
	{
		addMove(OneDownRight);
	}

	return moves;
}

void King::addMove(const Coordinate& c)
{
	if (board[c].getPiece() != nullptr)
	{
		//a)
		if (board[c].getPiece()->getIsWhite() == this->isWhite)
		{
			//that square is not placed into movablePositions
		}
		//b)
		else
		{
			moves.push_back(c);
		}
	}
	else
	{
		moves.push_back(c);
	}
}
