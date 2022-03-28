#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class StreetSign
{
private:

	//Objects
	sf::Sprite shape;

	//Resources


public:
	//Constructors / Destructors

	StreetSign(sf::Texture* texture, float pos_x, float pos_y, double scale);
	virtual ~StreetSign();

	//Functions

	void update();
	void render(sf::RenderWindow* window);
};

