#pragma once
#include "Entity.h"


using namespace std;
using namespace sf;

class Platform;

class Player{
public:
	int hp, energy;
	float speed;
	Sprite playerSprite;
	Texture playerTexture;

	Vector2f playerPosition;

	void draw(RenderWindow& window);
	void update(float deltatime, std::vector<std::unique_ptr<Platform>>& platforms);
		
	Player(int health, float aspeed, int aenergy);
};