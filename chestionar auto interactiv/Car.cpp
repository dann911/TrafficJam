#include "Car.h"


// Private functions


// Constructors / Destructors


Car::Car(std::string texture_name, float pos_x, float pos_y, double scale, int& num_cars)
{
	this->numberOfCars = num_cars;
	this->texture_name = texture_name;
	
	this->shape.setTexture(textureMap().textures[texture_name]);
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
		
}

bool Car::isPressed()
{
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}
