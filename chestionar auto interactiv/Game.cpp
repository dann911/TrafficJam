#include "Game.h"
#include <iostream>

//Private functions

void Game::initVariables()
{
	this->window = nullptr;
	std::srand(time(0));
	this->NumberOfCars = std::rand() % 3 + 2;
	std::cout << NumberOfCars << std::endl;
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
	if (this->texture.loadFromFile("Textures/basic intersection v2.PNG") == false)
		std::cout << "nu-l gasim pe cioaca" << std::endl;

	this->textures["CARBLUE-HOR"] = new sf::Texture();
	if (this->textures["CARBLUE-HOR"]->loadFromFile("Textures/car1-horizontal.png") == false)
		std::cout << "no car texture foun" << std::endl;

	this->textures["CARRED-VER"] = new sf::Texture();
	this->textures["CARRED-VER"]->loadFromFile("Textures/car2-vertical.png");

	this->textures["CARYELLOW-HOR"] = new sf::Texture();
	this->textures["CARYELLOW-HOR"]->loadFromFile("Textures/carYellow-horizontal.png");

	this->textures["CARGREEN-VER"] = new sf::Texture();
	this->textures["CARGREEN-VER"]->loadFromFile("Textures/carGREEN-vertical.png");

}

void Game::initSprites()
{
	//Set the map texture to the sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(120.f, 90.f));
	this->sprite.setScale(0.7, 0.7);


}

void Game::initCars()
{
	this->cars.push_back(new Car(this->textures["CARRED-VER"], car_positions[1 - 1].first, car_positions[1 - 1].second, 0.25));
	this->cars.push_back(new Car(this->textures["CARBLUE-HOR"], car_positions[2 - 1].first, car_positions[2 - 1].second, -0.25));
	this->cars.push_back(new Car(this->textures["CARGREEN-VER"], car_positions[3 - 1].first, car_positions[3 - 1].second, -0.25));
	this->cars.push_back(new Car(this->textures["CARYELLOW-HOR"], car_positions[4 - 1].first, car_positions[4 - 1].second, 0.25));

	std::random_shuffle(std::begin(cars), std::end(cars));

	while (this->cars.size() > this->NumberOfCars)
		cars.pop_back();
}



 //Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTextures();
	this->initSprites();
	this->initCars();
}

Game::~Game()
{
	delete this->window;

	// Delete textures
	
	for (auto& i : this->textures)
		delete i.second;

	for (auto* i : this->cars)
		delete i;
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
	//std::cout << "Mouse Pos: " << sf::Mouse::getPosition(*this->window).x << " " <<sf::Mouse::getPosition(*this->window).y << "\n";
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
	for (auto* car : this->cars)
	{
		car->reender(this->window);
	}

	this->window->display();
}
