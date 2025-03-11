#pragma once
#include "Entity.h"

using namespace sf;

class Platform : public Entity {
public:

	Texture TePlat;
	Sprite SpPlat;
	FloatRect platBounds;
	FloatRect platsideBounds;

	Platform();

	void draw(RenderWindow& window) override;
	void update(float deltatime) override; 
};