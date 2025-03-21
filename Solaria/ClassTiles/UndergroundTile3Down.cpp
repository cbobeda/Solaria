#include "UndergroundTile3Down.h"


UndergroundTile3Down::UndergroundTile3Down(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles coteterre3.2.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);

}

void UndergroundTile3Down::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void UndergroundTile3Down::setTile()
{

}