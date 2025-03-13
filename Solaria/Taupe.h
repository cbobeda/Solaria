#include "Entity.h"

class Taupe : public Entity
{
private:
	int hp = 1;
	float speed = 100;
	Texture taupeTexture;
	Sprite taupeSprite;
	Vector2f pos;
	Vector2f currentpos;
	float maxY;
	float minY;
	bool digging = false;

public:
	Taupe(sf::Vector2f pos);
	void update(float deltatime) override;
	void draw(sf::RenderWindow& window) override;
	~Taupe();

};