#include "UndergroundTile3Left.h"

UndergroundTile3Left::UndergroundTile3Left(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre3.4.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTile3Left::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTile3Left::setTile()
{

}