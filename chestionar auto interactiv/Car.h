#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Car
{
private:

	//Objects
	sf::Sprite shape;

	//Resources

public:
	// Constructors / Destructors

	Car(sf::Texture* texture, float pos_x, float pos_y, double scale);
	virtual ~Car();

	//Functions

	void update();
	void reender(sf::RenderWindow* window);
};

