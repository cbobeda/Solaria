#include "UndergroundTileDownLeft.h"

UndergroundTileDownLeft::UndergroundTileDownLeft(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre2.3.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileDownLeft::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileDownLeft::setTile()
{

}