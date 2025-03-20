#include "UndergroundTileUp.h"

UndergroundTileUp::UndergroundTileUp(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre1.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileUp::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileUp::setTile()
{

}