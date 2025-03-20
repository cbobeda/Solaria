#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileUpLeft : public Tiles
{
public:
	UndergroundTileUpLeft(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


