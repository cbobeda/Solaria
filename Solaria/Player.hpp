#pragma once
#include "Entity.h"
#include "ClassTiles/Tiles.h"

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
	void update(float deltatime,std::vector<std::shared_ptr<Tiles>>& platforms,Event& event);
	Vector2f getPosition() const;
	Player(int health = 100, float aspeed = 150.f, int aenergy = 100);
};