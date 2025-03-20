#include "UndergroundTile3Up.h"

UndergroundTile3Up::UndergroundTile3Up(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre3.1.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTile3Up::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTile3Up::setTile()
{

}