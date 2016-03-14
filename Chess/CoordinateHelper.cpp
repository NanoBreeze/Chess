#include "CoordinateHelper.h"





Coordinate CoordinateHelper::getCoordinateUp(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateDown(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateUpRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateUpLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateDownRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::getCoordinateDownLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::getMostUpCoordinate(Coordinate coordinate)
{
	int column = (int)coordinate % 8;


	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (7 * 8 + column);
}

Coordinate CoordinateHelper::getMostDownCoordinate(Coordinate coordinate)
{
	int column = (int)coordinate % 8;


	assert(column >= 0 && column <= 7);	//column must be on board

	return static_cast<Coordinate> (0 * 8 + column);	//we include 0 * 8 for consistency to show the row


}

Coordinate CoordinateHelper::getMostLeftCoordinate(Coordinate coordinate)
{
	int row = (int)coordinate / 8;


	assert(row >= 0 && row <= 7);	//row must be on board


	return static_cast<Coordinate> (row * 8 + 0);	//we include 0 for consistency to show the column

}

Coordinate CoordinateHelper::getMostRightCoordinate(Coordinate coordinate)
{
	int row = (int)coordinate / 8;


	assert(row >= 0 && row <= 7);	//column must be on board

	return static_cast<Coordinate> (row * 8 + 7);	//we include 7 for consistency to show the column;
}

Coordinate CoordinateHelper::getMostUpRightCoordinate(Coordinate coordinate)
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

Coordinate CoordinateHelper::getMostUpLeftCoordinate(Coordinate coordinate)
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

Coordinate CoordinateHelper::getMostDownRightCoordinate(Coordinate coordinate)
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

Coordinate CoordinateHelper::getMostDownLeftCoordinate(Coordinate coordinate)
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

Coordinate CoordinateHelper::TwoUpOneRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::TwoUpOneLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::OneUpTwoRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::OneUpTwoLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::TwoDownOneRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::TwoDownOneLeft(Coordinate coordinate)
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

Coordinate CoordinateHelper::OneDownTwoRight(Coordinate coordinate)
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

Coordinate CoordinateHelper::OneDownTwoLeft(Coordinate coordinate)
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

bool CoordinateHelper::checkIfInvalidCoordinate(int row, int column)
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

bool CoordinateHelper::checkIfInvalidCoordinate(int rc)
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
