#include "StreetSign.h"



//Constructors / Destructors

StreetSign::StreetSign(sf::Texture* texture, float pos_x, float pos_y, double scale)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(scale, scale);
}

StreetSign::~StreetSign()
{

}

//Functions

void StreetSign::update()
{

}

void StreetSign::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
}

