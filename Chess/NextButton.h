#pragma once
#include "CustomButton.h"

//pressing this button shows the position of the Pieces after this move
class NextButton : public CustomButton
{
public:
	NextButton(int x, int y);
	~NextButton();

	void handleClick(sf::Event) override;

private:



};

