#include "StateManager.h"

void StateManager::setSelectedSquare(Square* square)
{
	selectedSquare = square;
}

void StateManager::removeSelectedSquare()
{
	selectedSquare = nullptr;
}

Square* StateManager::getSelectedSquare() const
{
	return selectedSquare;
}



StateManager::StateManager()
{
}
