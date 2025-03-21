#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTile3Up : public Tiles
{
public:
	UndergroundTile3Up(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


