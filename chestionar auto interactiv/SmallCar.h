#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#include "TextureMap.h"

class SmallCar
{
private:

	sf::Sprite shape;

public:

	//Cons / Des

	SmallCar(std::string texture_name, float pos_x, float pos_y);
	virtual ~SmallCar();

	//Functions

	void update();
	void render(sf::RenderWindow* window);

};

