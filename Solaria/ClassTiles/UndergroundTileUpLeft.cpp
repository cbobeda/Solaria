#include "UndergroundTileUpLeft.h"

UndergroundTileUpLeft::UndergroundTileUpLeft(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre2.1.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileUpLeft::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileUpLeft::setTile()
{

}