#include "Platform.h"

Platform::Platform(Vector2i pos) {
	TePlat.loadFromFile("plat.jpg");
	SpPlat.setTexture(TePlat);
	SpPlat.setPosition(Vector2f(pos));
	platBounds = SpPlat.getGlobalBounds();
}


void Platform::draw(RenderWindow& window) {
	window.draw(SpPlat);
}

void Platform::update(float deltatime) {

}