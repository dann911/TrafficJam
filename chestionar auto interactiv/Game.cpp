#include "Game.h"
#include <iostream>

//Private functions

void Game::initVariables()
{
	this->window = nullptr;

	//Game logic

	std::srand(time(0));
	this->NumberOfCars = std::rand() % 2 + 2;

	this->decision = 0 + (rand() % (1 - 0 + 1)) == 1;
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





void Game::initSprites()
{
	//Set the map texture to the sprite
	this->sprite.setTexture(textureMap().textures["MAP"]);
	this->sprite.setPosition(sf::Vector2f(120.f, 90.f));
	this->sprite.setScale(0.7, 0.7);

	this->gameOver.setTexture(textureMap().textures["GAMEOVER"]);
}

void Game::initTexts()
{
	this->font.loadFromFile("Fonts/boge.ttf");

	this->scoreString = backup_string;
	this->scoreString += std::to_string(this->score);

	this->scoreText.setFont(font);
	this->scoreText.setString(this->scoreString);
	this->scoreText.setCharacterSize(16);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setPosition(0.f, 550.f);
}

void Game::initCars()
{
	this->cars.push_back(std::make_pair(new Car("CARRED-VER", car_positions[1 - 1].first, car_positions[1 - 1].second, 0.25, NumberOfCars), 1));
	this->cars.push_back(std::make_pair(new Car("CARBLUE-HOR", car_positions[2 - 1].first, car_positions[2 - 1].second, -0.25, NumberOfCars), 3));
	this->cars.push_back(std::make_pair(new Car("CARGREEN-VER", car_positions[3 - 1].first, car_positions[3 - 1].second, -0.25, NumberOfCars), 5));
	this->cars.push_back(std::make_pair(new Car("CARYELLOW-HOR", car_positions[4 - 1].first, car_positions[4 - 1].second, 0.25, NumberOfCars), 7));
	

	std::random_shuffle(std::begin(cars), std::end(cars));

	this->direction = this->cars[cars.size() - 1].second - 1;
	std::cout << "Direction: " << direction << std::endl;

	while (this->cars.size() > this->NumberOfCars)
		cars.pop_back();
	this->NumberOfCars = this->cars.size();
}

void Game::initPing()
{
	this->ping.setTexture(textureMap().textures["PING"]);
	this->ping.setPosition(ping_positions[direction / 2].first, ping_positions[direction / 2].second);
}



// Game algorithm private functions

void Game::output()
{
	std::cout << "The PRIORITY list for the selected root is: ";

	for (int i = 0; i < answer_list.size(); i++)
	{
		std::cout << this->answer_list[i] << " ";
	}
	std::cout << std::endl;
}

void Game::givePriority()
{
	
	
	int random_pos = rand() % NumberOfCars;
	this->priority.push_back(cars[random_pos].second);

	this->cars[random_pos].second = INT_MAX;

	for (int i = 0; i < this->cars.size(); i++)
	{
		if (abs(cars[i].second - priority[0]) == 4)
		{
			this->priority.push_back(cars[i].second);
			cars[i].second = INT_MAX;

			if (abs(priority[0] - direction) < abs(priority[1] - direction))   //trebuie sortat descrescator pentru ca prin push front se insereaza invers
				std::swap(priority[0], priority[1]);
			break;
		}
	}
}

void Game::getPriorityOrder()
{
	for (int i = 0; i < NumberOfCars; i++)
	{
		this->aux_cars.push_back(this->cars[i].second);
	}

	if (this->direction == 0)
		this->direction = 8;

	if (decision == 1)
	{
		this->givePriority();
	}

	for (int i = 0; i < this->cars.size(); i++)
	{
		if (this->cars[i].second != INT_MAX)
		{
			this->answer_list.push_back(cars[i].second);
		}
	}
	int phase = 0;

	sort(begin(answer_list), end(answer_list), [](int a, int b) {return a > b; });
	if (this->answer_list.size() != 0)
	{
		while (this->answer_list[0] > this->direction && phase < this->answer_list.size())    //inverted closkwise listg sort
		{
			this->answer_list.push_back(this->answer_list[0]);
			this->answer_list.pop_front();
			phase++;
		}
	}

	if (decision == 1)
	{
		int RandCase = rand() % 2;

		if (RandCase == 0)    // Drum cu prioritate
		{
			for (int i = 0; i < this->priority.size(); i++)
			{
				switch (this->priority[i])
				{
				case 1:
					this->streetSigns.push_back(new StreetSign("DRUM_CU_PRIORITATE_VER", sign_positions[0].first, sign_positions[0].second, 1.f));
					break;

				case 3:
					this->streetSigns.push_back(new StreetSign("DRUM_CU_PRIORITATE_HOR", sign_positions[1].first, sign_positions[1].second, -1.f));
					break;

				case 5:
					this->streetSigns.push_back(new StreetSign("DRUM_CU_PRIORITATE_VER", sign_positions[2].first, sign_positions[2].second, -1.f));
					break;

				case 7:
					this->streetSigns.push_back(new StreetSign("DRUM_CU_PRIORITATE_HOR", sign_positions[3].first, sign_positions[3].second, 1.f));
					break;
				}
			}
		}

		else if (RandCase == 1)  //Acorda prioritate
		{
			for (int i = 0; i < answer_list.size(); i++)
			{
				switch (this->answer_list[i])
				{
				case 1:
					this->streetSigns.push_back(new StreetSign("ACORDA_PRIORITATE_VER", sign_positions[0].first, sign_positions[0].second, 1.f));
					break;

				case 3:
					this->streetSigns.push_back(new StreetSign("ACORDA_PRIORITATE_HOR", sign_positions[1].first, sign_positions[1].second, -1.f));
					break;

				case 5:
					this->streetSigns.push_back(new StreetSign("ACORDA_PRIORITATE_VER", sign_positions[2].first, sign_positions[2].second, -1.f));
					break;

				case 7:
					this->streetSigns.push_back(new StreetSign("ACORDA_PRIORITATE_HOR", sign_positions[3].first, sign_positions[3].second, 1.f));
					break;
				}
			}
		}
	}

	for (int i = 0; i < priority.size(); i++)
	{
		this->answer_list.push_front(this->priority[i]);
	}

	for (int i = 0; i < cars.size(); i++)
	{
		cars[i].second = aux_cars[i];
	}
}

void Game::resetValues()
{
	this->NumberOfCars = std::rand() % 2 + 2;
	this->decision = 0 + (rand() % (1 - 0 + 1)) == 1;

	this->cars.erase(std::begin(cars), std::end(cars));
	this->streetSigns.erase(std::begin(streetSigns), std::end(streetSigns));
	this->answer_list.erase(std::begin(answer_list), std::end(answer_list));
	this->priority.erase(std::begin(priority), std::end(priority));
	for (int i = 0; i < 4; i++)
		isCarPressed[i] = false;
	smallCars.clear();
	width = 0;
	input_list.clear();
	aux_cars.clear();

}



 //Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initSprites();
	this->initTexts();
	this->initCars();
	this->initPing();
	this->getPriorityOrder();
	this->evaluate();
}

Game::~Game()
{
	delete this->window;

	// Delete textures

	for (auto& i : this->cars)
		delete i.first;

	for (auto* sign : this->streetSigns)
		delete sign;

	for (auto* s_car : this->smallCars)
		delete s_car;
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

			else if (this->ev.key.code == sf::Keyboard::Space && this->gameEnd == true)
			{
				std::system("CLS");
				this->gameEnd = false;
				this->score = -1;
				resetValues();
				initSprites();
				initCars();
				initPing();
				getPriorityOrder();
			}
			break;

		

		}
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateCarsButtons()
{
	for (int i=0; i<NumberOfCars; i++)
	{
		cars[i].first->update(this->mousePosView);
		
		if (cars[i].first->isPressed() == true && isCarPressed[i] == false)
		{
			isCarPressed[i] = true;
			std::cout << "pressed " << cars[i].second << std::endl;
			input_list.push_back(cars[i].second);

			this->smallCars.push_back(new SmallCar(cars[i].first->texture_name, this->width, 0.f));
			this->width += 50.f;
		}
	}
}

void Game::evaluate()
{
	for (int i = 0; i < input_list.size(); i++)
	{
		if (this->input_list[i] != this->answer_list[i])
		{
			this->gameEnd = true;
			this->score = -1;
			this->output();
			return;
		}
	}
	score++;  // if answers are correct, game continues
	
	this->initTexts();

	std::system("CLS");
	resetValues();
	initSprites();
	initCars();
	initPing();
	getPriorityOrder();
}


void Game::update()
{
	this->pollEvents();

	this->updateMousePositions();

	this->updateCarsButtons();

	if (this->input_list.size() == this->answer_list.size())
	{
		this->evaluate();
	}
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

	if (this->gameEnd == false)
	{
		// Draw game map
		this->window->draw(this->sprite);
		// Draw game objects
		for (auto& car : this->cars)
		{
			car.first->render(this->window);
		}
		this->window->draw(this->ping);
		for (auto* sign : this->streetSigns)
			sign->render(this->window);
		for (auto* s_car : this->smallCars)
			s_car->render(this->window);

		this->window->draw(this->scoreText);
		

	}
	else    /// GAME OVER screen
	{
		this->window->draw(this->gameOver);
	}

	
	this->window->display();
}
