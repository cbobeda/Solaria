#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class DirtTile : public Tiles
{
public:
	Sprite dirtSprite;
	Texture dirtTexture;
	DirtTile(sf::Vector2f pos);
	void draw(sf::RenderWindow& window) override;
	void setTile() override;
};

