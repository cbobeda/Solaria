#include "DirtTile.h"

DirtTile::DirtTile(sf::Vector2f pos)
{
	texture.loadFromFile("assets/tiles/tiles grass.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(1, 1);
}

void DirtTile::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void DirtTile::setTile()
{

}
