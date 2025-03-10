#include "Platform.h"

Platform::Platform() {
	TePlat.loadFromFile("plat.jpg");
	SpPlat.setTexture(TePlat);
	SpPlat.setPosition({ 500, 500 });
}


void Platform::draw(RenderWindow& window) {
	window.draw(SpPlat);
}

void Platform::update(float deltatime) {

}