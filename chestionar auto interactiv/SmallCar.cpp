#include "SmallCar.h"


//Cons / Des

SmallCar::SmallCar(std::string texture_name, float pos_x, float pos_y)
{
	for (int i = 1; i <= 4; i++)
		texture_name.pop_back();

	texture_name.push_back('-');
	texture_name.push_back('H');
	texture_name.push_back('O');
	texture_name.push_back('R');
	
	this->shape.setTexture(textureMap().textures[texture_name]);
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setScale(0.13, 0.13);
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

