#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileUpRight : public Tiles
{
public:
	UndergroundTileUpRight(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


