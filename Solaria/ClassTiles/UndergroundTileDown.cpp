#include "UndergroundTileDown.h"

UndergroundTileDown::UndergroundTileDown(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre4.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTileDown::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTileDown::setTile()
{

}