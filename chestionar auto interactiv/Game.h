#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <climits>

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
	bool decision;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;

	//Resources   ->cars
	std::map<std::string, sf::Texture*> textures;
	std::vector< std::pair <Car*, int> > cars;
	std::vector<std::pair<float, float> > car_positions =
	{
		{400, 358},  //down   1
		{448 + 64, 237 + 64},  //right   2
		{336 + 64, 190 + 64},  //up   3
		{290, 300}   //left   4
	};
	//            ->pings
	std::vector<std::pair<float, float> > ping_positions =
	{
		{367, 360},  //down   1
		{466, 311},  //right   2
		{411, 215},  //up   3
		{316, 263}   //left   4
	};
	int direction;

	std::vector<int> priority;
	std::deque<int> answer_list;

	//Map	
	sf::Texture texture;
	sf::Sprite sprite;

	//Map objects
	sf::Sprite ping;

	// Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initSprites();
	void initCars();
	void initPing();

	void output();
	void givePriority();
	void getPriorityOrder();

	void resetValues();

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

