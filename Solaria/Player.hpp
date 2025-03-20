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
	Sprite energySprite;
	Texture energyTexture;
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
	

	

	void draw(RenderWindow& window);
	void update(float deltatime,std::vector<std::shared_ptr<Tiles>>& platforms,RenderWindow& window, Event& event);
	void grapin(RenderWindow& window, vector<shared_ptr<Tiles>>& currentMap, float deltatime);
	//void deplacerCurseur(float deltatime);
	Vector2f getPosition() const;
	Player(int health = 100, float aspeed = 150.f, int aenergy = 14);
};