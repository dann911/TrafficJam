#pragma once

#include "Game.h"

class Car
{
private:



public:
	// Constructors / Destructors

	Car();
	virtual ~Car();

	//Functions

	void update();
	void reender(sf::RenderWindow* window);
};

