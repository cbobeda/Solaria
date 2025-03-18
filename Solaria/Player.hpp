#pragma once
#include "Entity.h"
#include "Tiles.h"

using namespace std;
using namespace sf;

class Platform;

class Player{
public:
	int hp, energy;
	float speed;
	Sprite playerSprite;
	Texture playerTexture;
	
	Texture grapinTexture;
	RectangleShape line;

	bool jump;
	bool hasToMoveDown;
	float initialY;
	float initialX;
	float maxJumpHeight;
	sf::Clock watchanime;
	sf::Clock jumpCooldown; 
	sf::Clock dashCooldown;
	float lastJumpTime;

	Vector2f playerPosition;
	

	

	void draw(RenderWindow& window);
	void update(float deltatime, std::vector<std::unique_ptr<Tiles>>& platforms, RenderWindow& window, Event event);
	void grapin(RenderWindow& window, vector<unique_ptr<Tiles>>& currentMap, float deltatime);
		
	
	Vector2f getPosition() const;
	Player(int health, float aspeed, int aenergy);
};