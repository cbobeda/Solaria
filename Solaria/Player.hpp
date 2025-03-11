#pragma once
#include "Entity.h"


using namespace std;
using namespace sf;

class Platform;

class Player: public Entity{
public:
	int hp, energy;
	float speed;
	Sprite playerSprite;
	Texture playerTexture;

	bool jump;           
	float initialY;
	float maxJumpHeight;
	sf::Clock jumpCooldown; 
	float lastJumpTime;

	Vector2f playerPosition;

	void draw(RenderWindow& window) override;
	void update(float deltatime) override;
		
	Player(int health, float aspeed, int aenergy, Platform* plat);

	Platform* platform;
};