#include "GroundTile.h"

GroundTile::GroundTile(sf::Vector2f pos)
{
	groundTexture.loadFromFile("ground.png");
	groundSprite.setTexture(groundTexture);
	groundSprite.setPosition(pos);
	groundSprite.setScale(1, 1);
}

void GroundTile::draw(sf::RenderWindow& window)
{
	window.draw(groundSprite);
}

void GroundTile::setTile()
{

}



