#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTileDownRight : public Tiles
{
public:
	UndergroundTileDownRight(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


