#include "UndergroundTileLeft.h"

UndergroundTileLeft::UndergroundTileLeft(sf::Vector2f pos)
{
	undergroundTexture.loadFromFile("assets/tiles/tiles coteterre2.png");
	undergroundSprite.setTexture(undergroundTexture);
	undergroundSprite.setPosition(pos);
	undergroundSprite.setScale(1, 1);

}

void UndergroundTileLeft::draw(sf::RenderWindow& window)
{
	window.draw(undergroundSprite);
}

void UndergroundTileLeft::setTile()
{

}