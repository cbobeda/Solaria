#include "Entity.h"
#include "Player.hpp"

class Missile : public Entity {
private:
	float speed = 10;
	Texture TextMissile;
	Sprite SpMissile;
	Vector2f MiisilePos;


public:

	float lifetime = 10;

	Missile(Vector2f MissilePos);
	void draw(RenderWindow& window) override;
	void update(float deltatime) override;
	void FollowPlayer(Player player);
	~Missile();

	FloatRect getBounds() {
		return SpMissile.getGlobalBounds();
	}
};