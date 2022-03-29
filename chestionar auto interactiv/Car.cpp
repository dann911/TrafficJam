#include "Car.h"


// Private functions


void Car::initChoiceBox()
{
	std::cout << "number of cars  " << numberOfCars << std::endl;
	switch(this->numberOfCars)
	{
		
		case 2:
			std::cout << "meets case 2" << std::endl;
			this->choiceBox.setTexture(textureMap().textures["2OPTION"]);
			this->choiceBox.setPosition(0.f, 0.f);
				//this->shape.getGlobalBounds().width - this->choiceBox.getGlobalBounds().width,
				//this->shape.getGlobalBounds().height - this->choiceBox.getGlobalBounds().height
			//);
			break;

		case 3:
			std::cout << "meets case 3" << std::endl;
			this->choiceBox.setTexture(textureMap().textures["PING"]);
			this->choiceBox.setPosition(0.f, 0.f);
			//this->shape.getGlobalBounds().width - this->choiceBox.getGlobalBounds().width,
			//this->shape.getGlobalBounds().height - this->choiceBox.getGlobalBounds().height
		//);
			break;
	}

	
}

// Constructors / Destructors


Car::Car(sf::Texture texture, float pos_x, float pos_y, double scale, int& num_cars)
{
	this->numberOfCars = num_cars;
	this->initChoiceBox();
	
	this->shape.setTexture(texture);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(scale, scale);

	this->idleColor = this->shape.getColor();
	this->buttonState = BTN_IDLE;

	
}



Car::~Car()
{
	
}

//Functions

void Car::update(const sf::Vector2f mousePos)
{
	
	
	// Update booleans for hover and pressed

	//Idle
	this->buttonState = BTN_IDLE;
	this->shape.setColor(this->idleColor);
	
	//Hover
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->shape.setColor(this->hoverColor);
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_PRESSED;
			this->shape.setColor(this->pressedColor);
		}
		
	}
}

void Car::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
	window->draw(this->choiceBox);
	if (this->buttonState == BTN_PRESSED)
	{
		//window->draw(this->choiceBox);
		//std::cout << "true" << std::endl;
	}
		
}

bool Car::isPressed()
{
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}
