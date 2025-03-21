#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTile3Right : public Tiles
{
public:
	UndergroundTile3Right(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


