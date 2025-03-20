#include "UndergroundTileDownRight.h"

UndergroundTileDownRight::UndergroundTileDownRight(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre2.4.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileDownRight::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileDownRight::setTile()
{

}