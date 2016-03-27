#pragma once
#include "CustomButton.h"
#include <fstream>
#include <iostream>
#include "Board.h"
#include "Coordinate.h"

//creates a text file containing the piece's position on the Board
class SaveButton :	public CustomButton
{
public:
	SaveButton(int x, int y);
	~SaveButton();

	//if this button is clicked, we make a text file containing the coordinates that have pieces, which pieces, and colour of pieces
	void handleClick(sf::Event) override;

private:


};

