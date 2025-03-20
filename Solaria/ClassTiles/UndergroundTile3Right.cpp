#include "UndergroundTile3Right.h"

UndergroundTile3Right::UndergroundTile3Right(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre3.3.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTile3Right::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTile3Right::setTile()
{

}