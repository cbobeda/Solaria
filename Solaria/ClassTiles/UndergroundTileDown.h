#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileDown : public Tiles
{
public:
	UndergroundTileDown(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


