#include "Game.h"
#include <iostream>

//Private functions

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->VideoMode.height = 600;
	this->VideoMode.width = 800;

	//this->VideoMode.getDesktopMode;

	this->window = new sf::RenderWindow(this->VideoMode, "Traffic minigame", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
    //Load map texture from file
	if (this->texture.loadFromFile("Textures/basic intersection v1.PNG") == false)
		std::cout << "nu-l gasim pe cioaca" << std::endl;

}

void Game::initSprites()
{
	//Set the map texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(120.f, 90.f));
	this->sprite.setScale(0.7, 0.7);
}



 //Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTextures();
	this->initSprites();
}

Game::~Game()
{
	delete this->window;

	// Delete textures
	
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	//Mouse Position relative to the window
	std::cout << "Mouse Pos: " << sf::Mouse::getPosition(*this->window).x << " " <<sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render()
{
	/*
	     return void

	     -clear old frame
		 -render objects
		 -display frame in window

		 Render the game objects
	*/

	this->window->clear(sf::Color(7, 0, 25));

	// Draw game map
	this->window->draw(this->sprite);
	// Draw game objects
	this->window->draw(this->CarSprite);

	this->window->display();
}
