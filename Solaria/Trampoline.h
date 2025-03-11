#pragma once 
#include "Entity.h"


using namespace std;
using namespace sf;

class Trampoline : public Entity {
public:

	Texture TextTramp;
	Sprite SpTramp;

	Trampoline();

	void draw(RenderWindow& window) override; 
	void update(float deltatime) override;
};
