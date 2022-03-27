#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Car.h"

/*
*    Class that acts as the game engine.
*    Wrapper class.
*/

class Game
{
private:
	//Variables
	int NumberOfCars;


	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Car*> cars;
	std::vector<std::pair<float, float> > car_positions =
	{
		{400, 358},  //down   2
		{448 + 64, 237 + 64},  //right   4
		{336 + 64, 190 + 64},  //up   6
		{290, 300}   //left   8
	};

	std::vector<std::pair<float, float> > ping_positions =
	{
		{367, 360},  //down   1
		{466, 311},  //right   3
		{411, 215},  //up   5
		{316, 263}   //left   7
	};
	int freq[4];

	//Map	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite ping;
	//Map objects
	

	// Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initSprites();
	void initCars();
	void initPing();

public:
	// Constructos / Destructors
	Game(); 
	virtual ~Game(); 

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};

