#pragma once
#include <SFML/Graphics.hpp>
class Tiles
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void setTile() = 0;
};



