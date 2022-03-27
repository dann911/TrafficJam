#include "Car.h"


// Private functions



// Constructors / Destructors

Car::Car(sf::Texture* texture, float pos_x, float pos_y, double scale)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(scale, scale);
}

Car::~Car()
{

}

//Functions

void Car::update()
{

}

void Car::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
}
