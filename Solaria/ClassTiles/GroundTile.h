#pragma once
#include "Tiles.h"
using namespace std;
using namespace sf;

class GroundTile : public Tiles
{
	public:
		Sprite groundSprite;
		Texture groundTexture;
		GroundTile(sf::Vector2f pos);
		void draw(sf::RenderWindow& window) override;
		void setTile() override;
};

