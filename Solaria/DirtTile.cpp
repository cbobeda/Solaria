#include "DirtTile.h"

DirtTile::DirtTile(sf::Vector2f pos)
{
	dirtTexture.loadFromFile("dirt.png");
	dirtSprite.setTexture(dirtTexture);
	dirtSprite.setPosition(pos);
	dirtSprite.setScale(1, 1);
}

void DirtTile::draw(sf::RenderWindow& window)
{
	window.draw(dirtSprite);
}

void DirtTile::setTile()
{

}
