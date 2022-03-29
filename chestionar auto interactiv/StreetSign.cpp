#include "StreetSign.h"



//Constructors / Destructors

StreetSign::StreetSign(std::string texture_name, float pos_x, float pos_y, double scale)
{
	this->shape.setTexture(textureMap().textures[texture_name]);
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

