#include "UndergroundTile.h"

UndergroundTile::UndergroundTile(sf::Vector2f pos)
{
	undergroundTexture.loadFromFile("assets/tiles/tiles coteterre4.png");
	undergroundSprite.setTexture(undergroundTexture);
	undergroundSprite.setPosition(pos);
	undergroundSprite.setScale(1, 1);

}

void UndergroundTile::draw(sf::RenderWindow& window)
{
	window.draw(undergroundSprite);
}

void UndergroundTile::setTile()
{

}