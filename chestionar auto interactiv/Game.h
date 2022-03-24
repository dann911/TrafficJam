#pragma once


#include <iostream>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
*    Class that acts as the game engine.
*    Wrapper class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;

	//Resources
	

	//Map	
	sf::Texture texture;
	sf::Sprite sprite;

	//Map objects
	sf::Texture CarTexture1;
	sf::Sprite CarSprite;

	

	// Private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initSprites();
	void initObjectSprites();

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

