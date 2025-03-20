#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileRight : public Tiles
{
public:
	UndergroundTileRight(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


