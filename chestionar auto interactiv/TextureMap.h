#pragma once

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextureMap
{
	//Private functions
	void initTextures();
public:

	// Constructors / Destructors

	TextureMap();
	virtual ~TextureMap();

	// Resources
	std::map<std::string, sf::Texture> textures;
};

TextureMap& textureMap();