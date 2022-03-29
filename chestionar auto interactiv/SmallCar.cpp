#include "SmallCar.h"


//Cons / Des

SmallCar::SmallCar(std::string texture_name, float pos_x, float pos_y)
{
	this->shape.setTexture(textureMap().textures["PING"]);
	//this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(0.1, 0.1);

	std::cout << "small car initiated" << std::endl;
}

SmallCar::~SmallCar()
{
}

//Functions

void SmallCar::update()
{

}

void SmallCar::render(sf::RenderWindow* window)
{
	window->draw(this->shape);
}

