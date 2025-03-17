#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileLeft : public Tiles
{
public:
	Sprite undergroundSprite;
	Texture undergroundTexture;
	UndergroundTileLeft(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


