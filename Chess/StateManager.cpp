#include "StateManager.h"

StateManager& StateManager::getInstance()
{
	static StateManager statemanager;
	return statemanager;
}

void StateManager::setSelectedSquare(Square* square)
{
	selectedSquare = square;
}

void StateManager::removeSelectedSquare()
{
	selectedSquare = nullptr;
}

std::stack<Turn> StateManager::getTurns() const
{
	return turns;
}

Square* StateManager::getSelectedSquare() const
{
	return selectedSquare;
}



StateManager::StateManager()
{
}
