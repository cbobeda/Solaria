#include "UndergroundTileRight.h"

UndergroundTileRight::UndergroundTileRight(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre2.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileRight::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileRight::setTile()
{

}