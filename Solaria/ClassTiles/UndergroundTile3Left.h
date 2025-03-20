#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class UndergroundTile3Left : public Tiles
{
public:
	UndergroundTile3Left(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};


