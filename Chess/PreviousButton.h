#pragma once
#include "CustomButton.h"

//pressing this button shows the position of the Pieces prior to this move
class PreviousButton : public CustomButton
{
public:
	PreviousButton(int x, int y);
	~PreviousButton();

	void handleClick(sf::Event) override;

private:


};

