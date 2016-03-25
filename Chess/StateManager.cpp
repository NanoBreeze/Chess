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

MovesDisplay& StateManager::getMovesDisplay()
{
	movesDisplay.setTurns(turns);
	return movesDisplay;
}

std::stack<Turn>& StateManager::getTurns() 
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
