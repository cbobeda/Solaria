#pragma once
#include "Entity.h"
#include "Player.hpp"



class Winitem : public Entity
{
public:
	Sprite winitemSprite;
	Texture winitemTexture;
	Player* player;

	void draw(RenderWindow& window) override;
	void update(float deltatime) override;
	Winitem(Vector2f position, Player* player);
	~Winitem();

};

