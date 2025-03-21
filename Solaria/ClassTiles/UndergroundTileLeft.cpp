#include "UndergroundTileLeft.h"

UndergroundTileLeft::UndergroundTileLeft(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre3.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileLeft::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileLeft::setTile()
{

}