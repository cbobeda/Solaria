#include "UndergroundTileUpRight.h"

UndergroundTileUpRight::UndergroundTileUpRight(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre2.2.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileUpRight::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileUpRight::setTile()
{

}