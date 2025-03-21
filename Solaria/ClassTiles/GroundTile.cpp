#include "GroundTile.h"

GroundTile::GroundTile(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles terre.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);
}

void GroundTile::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void GroundTile::setTile()
{

}



