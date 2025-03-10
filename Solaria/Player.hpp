#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
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
		
	Player(int health, float aspeed, int aenergy);
};