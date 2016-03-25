#include "CoordinateHelper.h"





Coordinate CoordinateHelper::getCoordinateUp(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row++;

	if (checkIfInvalidCoordinate(row, column))
	{
		return Coordinate::Invalid;
	}

	assert(row >= 0 && row <= 7); //row must still be on board
	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateDown(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row--;

	if (checkIfInvalidCoordinate(row, column))
	{
		return Coordinate::Invalid;
	}

	assert(row >= 0 && row <= 7);	//row must still be on board
	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	column--;

	if (checkIfInvalidCoordinate(row, column))
	{
		return Coordinate::Invalid;
	}

	assert(column >= 0 && column <= 7);	//column must be greater than or equal to 0, otherwise, not on board
	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	column++;

	if (checkIfInvalidCoordinate(row, column))
	{
		return Coordinate::Invalid;
	}

	assert(column >= 0 && column <= 7);	//column must be on board
	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateUpRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row++;
	column++;

	if (checkIfInvalidCoordinate(row, column))
	{
		return Coordinate::Invalid;
	}


	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateUpLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row++;
	column--;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateDownRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row--;
	column++;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getCoordinateDownLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row--;
	column--;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getMostUpCoordinate(const Coordinate& coordinate)
{
	int column = (int)coordinate % 8;


	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (7 * 8 + column);
}

Coordinate CoordinateHelper::getMostDownCoordinate(const Coordinate& coordinate)
{
	int column = (int)coordinate % 8;


	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (0 * 8 + column);	//we include 0 * 8 for consistency to show the row


}

Coordinate CoordinateHelper::getMostLeftCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;


	assert(row >= 0 && row <= 7);	//row must be on board


	return static_cast<Coordinate> (row * 8 + 0);	//we include 0 for consistency to show the column

}

Coordinate CoordinateHelper::getMostRightCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;


	assert(row >= 0 && row <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + 7);	//we include 7 for consistency to show the column;
}

Coordinate CoordinateHelper::getMostUpRightCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	//keep incrementing until we can't increment any more, that is the up-right most row/column
	while (row <= 7 && column <= 7)
	{
		//prevents row or column from being 8 
		if (row == 7 || column == 7)
		{
			break;
		}

		row++;
		column++;
	}


	assert(row >= 0 && row <= 7);	//column must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getMostUpLeftCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	//keep incrementing until we can't increment any more, that is the up-left most row/column
	while (row <= 7 && column >= 0)
	{
		//prevents row or column from being 8 
		if (row == 7 || column == 0)
		{
			break;
		}

		row++;
		column--;
	}

	assert(row >= 0 && row <= 7);	//column must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getMostDownRightCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	//keep incrementing until we can't increment any more, that is the down-right most row/column
	while (row >= 0 && column <= 7)
	{
		//prevents row or column from being 8 
		if (row == 0 || column == 7)
		{
			break;
		}

		row--;
		column++;
	}

	assert(row >= 0 && row <= 7);	//column must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::getMostDownLeftCoordinate(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	//keep incrementing until we can't increment any more, that is the down-left most row/column
	while (row >= 0 && column >= 7)
	{
		//prevents row or column from being 8 
		if (row == 0 || column == 0)
		{
			break;
		}
		row--;
		column--;
	}

	assert(row >= 0 && row <= 7);	//column must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::TwoUpOneRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row += 2;
	column++;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::TwoUpOneLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row += 2;
	column--;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);;
}

Coordinate CoordinateHelper::OneUpTwoRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row ++;
	column += 2;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::OneUpTwoLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row ++;
	column -= 2;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::TwoDownOneRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row -= 2;
	column++;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);;
}

Coordinate CoordinateHelper::TwoDownOneLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row -= 2;
	column--;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::OneDownTwoRight(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row--;
	column += 2;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

Coordinate CoordinateHelper::OneDownTwoLeft(const Coordinate& coordinate)
{
	int row = (int)coordinate / 8;
	int column = (int)coordinate % 8;

	row--;
	column -= 2;

	if (checkIfInvalidCoordinate(row, column)) { return Coordinate::Invalid; }

	assert(row >= 0 && row <= 7);	//row must be on board
	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + column);
}

bool CoordinateHelper::checkIfInvalidCoordinate(const int& row, const int& column)
{
	if (!(row >= 0 && row <= 7) || !(column >= 0 && column <= 7))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CoordinateHelper::checkIfInvalidCoordinate(const int& rc)
{
	if (!(rc >= 0 && rc <= 7))
	{
		return true;
	}
	else
	{
		return false;
	}
}
