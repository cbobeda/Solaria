#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileUp : public Tiles
{
public:
	UndergroundTileUp(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


