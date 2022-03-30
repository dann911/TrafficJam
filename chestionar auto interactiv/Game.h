#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <climits>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Car.h"
#include "StreetSign.h"
#include "TextureMap.h"
#include "SmallCar.h"

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

	//Mouse

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;

	//Game Over and other accessors
	sf::Sprite gameOver;
	sf::Text scoreText;
	sf::Font font;
	std::string scoreString = "Score: ";
	std::string backup_string = scoreString;
	
	//Resources 
	float width = 0.f;

	//    ->cars

	std::vector< int > aux_cars;
	std::vector< std::pair <Car*, int> > cars;
	std::vector< std::pair<float, float> > car_positions =
	{
		{400, 358},  //down   1
		{448 + 64, 237 + 64},  //right   3
		{336 + 64, 190 + 64},  //up   5
		{290, 300}   //left   7
	};

	//            ->pings
	
	std::vector< std::pair<float, float> > ping_positions = 
	{
		{367, 360},  //down   2
		{466, 311},  //right   4
		{411, 215},  //up   6
		{316, 263}   //left   8
	};
	
	int direction;

	//     ->street signs

	std::vector< std::pair<float, float> > sign_positions =
	{
		{460, 361},  //down   1
		{468 + 24, 208 + 40},  //right   3
		{321 + 24, 210 + 40},  //up   5
		{309, 355}   //left   7
	};
	std::vector< StreetSign* > streetSigns;

	//      ->other

	std::vector<int> priority;
	std::deque<int> answer_list;
	std::vector< int > input_list;

	bool isCarPressed[4];

	//Map	
	sf::Texture texture;
	sf::Sprite sprite;

	//Map objects
	sf::Sprite ping;
	sf::Sprite questionbox1;
	sf::Sprite questionbox2;

	std::vector< SmallCar* > smallCars;

	// Private functions
	void initVariables();
	void initWindow();
	void initSprites();
	void initTexts();
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

	//Variables
	bool gameEnd = false;
	int score = -1;

	//Functions
	
	void pollEvents();
	void updateMousePositions();
	void updateCarsButtons();
	void evaluate();
	void update();
	void render();
};

