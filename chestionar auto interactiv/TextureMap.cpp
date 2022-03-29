#include "TextureMap.h"

//Private functions

void TextureMap::initTextures()
{

}


// Constructors / Destructors

TextureMap::TextureMap()
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

TextureMap::~TextureMap()
{
}
