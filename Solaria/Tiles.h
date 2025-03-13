#pragma once
#include <SFML/Graphics.hpp>
class Tiles
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void setTile() = 0;
};



