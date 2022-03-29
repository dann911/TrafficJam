#pragma once

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureMap
{
	//Private functions
public:

	// Constructors / Destructors

	TextureMap();
	virtual ~TextureMap();

	// Resources
	std::map<std::string, sf::Texture> textures;
};

