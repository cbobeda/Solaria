#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

using namespace std;
using namespace sf;

class Platform : public Entity {
public:

	Texture TePlat;
	Sprite SpPlat;

	Platform();

	void draw(RenderWindow& window) override;
	void update(float deltatime) override; 
};