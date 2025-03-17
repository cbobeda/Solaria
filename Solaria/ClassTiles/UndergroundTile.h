#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTile : public Tiles
{
public:
	Sprite undergroundSprite;
	Texture undergroundTexture;
	UndergroundTile(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


