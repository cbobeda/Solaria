#include "Entity.h"

class Platform;

class Boss : public Entity {
private:

	int hp;
	float speed = 1;
	float leftlimite = 600;
	float righlimite = 1600;
	float direction = 1;
	Texture TextBoss;
	Sprite SpriteBoss;

	Clock clock;
	bool isWaiting = false;
	float pauseDuration = 1;

	bool jump;
	bool hasToMoveDown;
	float initialY;
	float initialX;
	float maxJumpHeight;
	sf::Clock watchanime;
	sf::Clock jumpCooldown;
	sf::Clock dashCooldown;
	float lastJumpTime;
	
public:

	Boss(int health);

	FloatRect getBounds() {
		return SpriteBoss.getGlobalBounds();
	}

	void draw(RenderWindow& window) override;
	void update(float deltatime) override;
	~Boss();
};
