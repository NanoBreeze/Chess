#include "Helper.h"



Helper::Helper()
{
}

 int Helper::getRowFromCoordinate(Coordinate coordinate)
{
	return ((int)coordinate) / 8;
}

int Helper::getColumnFromCoordinate(Coordinate coordinate)
{
	return ((int)coordinate) % 8;
}
