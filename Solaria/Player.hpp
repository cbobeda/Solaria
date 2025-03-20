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
	Texture runTexture;
	Sprite energySprite;
	Texture energyTexture;
	Sprite lifeSprite;
	Texture lifeTexture;
	Texture grapinTexture;
	RectangleShape line;
	
	Texture CurseurTexture;
	Sprite CurseurSprite;

	bool jump;
	bool hasToMoveDown;
	float initialY;
	float initialX;
	float maxJumpHeight;
	sf::Clock watchanime;
	sf::Clock energyreload;
	sf::Clock jumpCooldown; 
	sf::Clock dashCooldown;
	float lastJumpTime;

	Vector2f playerPosition;
	Vector2f viewCenter;
	Vector2f viewSize;

	IntRect idleRect;
	IntRect runRect;
	
	bool moving;
	
	void draw(RenderWindow& window);
	void update(float deltatime,std::vector<std::shared_ptr<Tiles>>& platforms,RenderWindow& window, Event& event);
	void grapin(RenderWindow& window, vector<shared_ptr<Tiles>>& currentMap,View& view, float deltatime);
	void getdamage();
	Vector2f getPosition() const;
	Player(int health = 90, float aspeed = 150.f, int aenergy = 14);
};