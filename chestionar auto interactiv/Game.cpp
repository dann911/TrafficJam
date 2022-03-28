#include "Game.h"
#include <iostream>

//Private functions

void Game::initVariables()
{
	this->window = nullptr;
	std::srand(time(0));
	this->NumberOfCars = std::rand() % 2 + 2;
	std::cout << NumberOfCars << std::endl;

	this->decision = 0 + (rand() % (1 - 0 + 1)) == 1;
	std::cout << "Descision is: " << this->decision << std::endl;
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
	this->textures["MAP"] = new sf::Texture();
	this->textures["MAP"]->loadFromFile("Textures/basic intersection v2.PNG");

	this->textures["CARBLUE-HOR"] = new sf::Texture();
	if (this->textures["CARBLUE-HOR"]->loadFromFile("Textures/car1-horizontal.png") == false)
		std::cout << "no car texture foun" << std::endl;

	this->textures["CARRED-VER"] = new sf::Texture();
	this->textures["CARRED-VER"]->loadFromFile("Textures/car2-vertical.png");

	this->textures["CARYELLOW-HOR"] = new sf::Texture();
	this->textures["CARYELLOW-HOR"]->loadFromFile("Textures/carYellow-horizontal.png");

	this->textures["CARGREEN-VER"] = new sf::Texture();
	this->textures["CARGREEN-VER"]->loadFromFile("Textures/carGREEN-vertical.png");

	this->textures["PING"] = new sf::Texture();
	this->textures["PING"]->loadFromFile("Textures/Ping.png");

	this->textures["ACORDA_PRIORITATE_VER"] = new sf::Texture();
	this->textures["ACORDA_PRIORITATE_VER"]->loadFromFile("Textures/AcordaPrioritate.png");

	this->textures["ACORDA_PRIORITATE_HOR"] = new sf::Texture();
	this->textures["ACORDA_PRIORITATE_HOR"]->loadFromFile("Textures/AcordaPrioritate - hor.png");

	this->textures["DRUM_CU_PRIORITATE_VER"] = new sf::Texture();
	this->textures["DRUM_CU_PRIORITATE_VER"]->loadFromFile("Textures/DrumCuPrioritate.png");

	this->textures["DRUM_CU_PRIORITATE_HOR"] = new sf::Texture();
	this->textures["DRUM_CU_PRIORITATE_HOR"]->loadFromFile("Textures/DrumCuPrioritate - hor.png");

	this->textures["1.3"] = new sf::Texture();
	this->textures["1.3"]->loadFromFile("Textures/1.3.png");
	 
	this->textures["2.3"] = new sf::Texture();
	this->textures["2.3"]->loadFromFile("Textures/2.3.png");

	this->textures["3.3"] = new sf::Texture();
	this->textures["3.3"]->loadFromFile("Textures/3.3.png");

	this->textures["1.2"] = new sf::Texture();
	this->textures["1.2"]->loadFromFile("Textures/1.2.png");

	this->textures["2.2"] = new sf::Texture();
	this->textures["2.2"]->loadFromFile("Textures/2.2.png");

	this->textures["3OPTIONS"] = new sf::Texture();
	this->textures["3OPTIONS"]->loadFromFile("Textures/3option.png");

	this->textures["2OPTIONS"] = new sf::Texture();
	this->textures["2OPTIONS"]->loadFromFile("Textures/option2.png");

	this->textures["1.3CHECK"] = new sf::Texture();
	this->textures["1.3CHECK"]->loadFromFile("Textures/right1.3.png");

	this->textures["2.3CHECK"] = new sf::Texture();
	this->textures["2.3CHECK"]->loadFromFile("Textures/right2.3.png");

	this->textures["3.3CHECK"] = new sf::Texture();
	this->textures["3.3CHECK"]->loadFromFile("Textures/right3.3.png");

	this->textures["1.2CHECK"] = new sf::Texture();
	this->textures["1.2CHECK"]->loadFromFile("Textures/right1.2.png");

	this->textures["2.2CHECK"] = new sf::Texture();
	this->textures["2.2CHECK"]->loadFromFile("Textures/right2.2.png");




}

void Game::initSprites()
{
	//Set the map texture to the sprite
	this->sprite.setTexture(*textures["MAP"]);
	this->sprite.setPosition(sf::Vector2f(120.f, 90.f));
	this->sprite.setScale(0.7, 0.7);


}

void Game::initCars()
{
	this->cars.push_back(std::make_pair(new Car(this->textures["CARRED-VER"], car_positions[1 - 1].first, car_positions[1 - 1].second, 0.25), 1));
	this->cars.push_back(std::make_pair(new Car(this->textures["CARBLUE-HOR"], car_positions[2 - 1].first, car_positions[2 - 1].second, -0.25), 3));
	this->cars.push_back(std::make_pair(new Car(this->textures["CARGREEN-VER"], car_positions[3 - 1].first, car_positions[3 - 1].second, -0.25), 5));
	this->cars.push_back(std::make_pair(new Car(this->textures["CARYELLOW-HOR"], car_positions[4 - 1].first, car_positions[4 - 1].second, 0.25), 7));

	std::random_shuffle(std::begin(cars), std::end(cars));

	this->direction = this->cars[cars.size() - 1].second - 1;
	std::cout << "Direction: " << direction << std::endl;

	while (this->cars.size() > this->NumberOfCars)
		cars.pop_back();
	this->NumberOfCars = this->cars.size();
}

void Game::initPing()
{
	this->ping.setTexture(*textures["PING"]);
	this->ping.setPosition(ping_positions[direction / 2].first, ping_positions[direction / 2].second);
}

void Game::initChoiseBox()
{

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
	std::cout << "Number of cars: " << NumberOfCars << std::endl;
	this->priority.push_back(cars[random_pos].second);
	std::cout << "PRIORITY given to: " << cars[random_pos].second << std::endl;

	this->cars[random_pos].second = INT_MAX;

	for (int i = 0; i < this->cars.size(); i++)
	{
		if (abs(cars[i].second - priority[0]) == 4)
		{
			this->priority.push_back(cars[i].second);
			std::cout << "PRIORITY given to: " << this->cars[i].second << std::endl;
			cars[i].second = INT_MAX;

			if (abs(priority[0] - direction) < abs(priority[1] - direction))   //trebuie sortat descrescator pentru ca prin push front se insereaza invers
				std::swap(priority[0], priority[1]);
			break;
		}
	}
}

void Game::getPriorityOrder()
{
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
					this->streetSigns.push_back(new StreetSign(this->textures["DRUM_CU_PRIORITATE_VER"], sign_positions[0].first, sign_positions[0].second, 1.f));
					break;

				case 3:
					this->streetSigns.push_back(new StreetSign(this->textures["DRUM_CU_PRIORITATE_HOR"], sign_positions[1].first, sign_positions[1].second, -1.f));
					break;

				case 5:
					this->streetSigns.push_back(new StreetSign(this->textures["DRUM_CU_PRIORITATE_VER"], sign_positions[2].first, sign_positions[2].second, -1.f));
					break;

				case 7:
					this->streetSigns.push_back(new StreetSign(this->textures["DRUM_CU_PRIORITATE_HOR"], sign_positions[3].first, sign_positions[3].second, 1.f));
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
					this->streetSigns.push_back(new StreetSign(this->textures["ACORDA_PRIORITATE_VER"], sign_positions[0].first, sign_positions[0].second, 1.f));
					break;

				case 3:
					this->streetSigns.push_back(new StreetSign(this->textures["ACORDA_PRIORITATE_HOR"], sign_positions[1].first, sign_positions[1].second, -1.f));
					break;

				case 5:
					this->streetSigns.push_back(new StreetSign(this->textures["ACORDA_PRIORITATE_VER"], sign_positions[2].first, sign_positions[2].second, -1.f));
					break;

				case 7:
					this->streetSigns.push_back(new StreetSign(this->textures["ACORDA_PRIORITATE_HOR"], sign_positions[3].first, sign_positions[3].second, 1.f));
					break;
				}
			}
		}
	}

	
	this->output();

	for (int i = 0; i < priority.size(); i++)
	{
		this->answer_list.push_front(this->priority[i]);
	}
	this->output();
}

void Game::resetValues()
{
	this->NumberOfCars = std::rand() % 2 + 2;
	std::cout << NumberOfCars << std::endl;
	this->decision = 0 + (rand() % (1 - 0 + 1)) == 1;
	std::cout << "Descision is: " << this->decision << std::endl;

	this->cars.erase(std::begin(cars), std::end(cars));
	this->streetSigns.erase(std::begin(streetSigns), std::end(streetSigns));
	this->answer_list.erase(std::begin(answer_list), std::end(answer_list));
	this->priority.erase(std::begin(priority), std::end(priority));
}




 //Constructors / Destructors

Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initTextures();
	this->initSprites();
	this->initCars();
	this->initPing();
	this->getPriorityOrder();
	this->initChoiseBox();
}

Game::~Game()
{
	delete this->window;

	// Delete textures
	
	for (auto& i : this->textures)
		delete i.second;

	for (auto& i : this->cars)
		delete i.first;

	for (auto* sign : this->streetSigns)
		delete sign;
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
			else if (this->ev.key.code == sf::Keyboard::Space)
			{
				std::system("CLS");
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

void Game::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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
	for (auto& car : this->cars)
	{
		car.first->render(this->window);
	}
	this->window->draw(this->ping);
	for (auto* sign : this->streetSigns)
		sign->render(this->window);

	this->window->display();
}
