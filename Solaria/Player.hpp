#pragma once
#include "Entity.h"


using namespace std;
using namespace sf;

class Player: public Entity{
public:
	int hp, energy;
	float speed;
	Sprite playerSprite;
	Texture playerTexture;

	Vector2f playerPosition;

	void draw(RenderWindow& window) override;
	void update(float deltatime) override;
	Vector2f getPosition() const;
		
	Player(int health, float aspeed, int aenergy);
};