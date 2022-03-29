#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#include "TextureMap.h"

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };

class Car
{
private:
	
	short unsigned buttonState;
	
	//Objects
	sf::Sprite shape;
	sf::Sprite choiceBox;
	//Resources
	sf::Event ev;

	//Colors
	sf::Color idleColor = sf::Color(160, 160, 160, 0);
	sf::Color hoverColor = sf::Color(160, 160, 160, 80);
	sf::Color pressedColor = sf::Color(160, 160, 160, 120);

	//Private functions

	void initChoiceBox();

	

public:
	
	
	// Constructors / Destructors

	Car(sf::Texture texture, float pos_x, float pos_y, double scale, int& num_cars);
	virtual ~Car();

	//Resources
	int numberOfCars;
	TextureMap& textureMap();

	//Functions

	void update(const sf::Vector2f mousePos);
	void render(sf::RenderWindow* window);

	bool isPressed();
};

