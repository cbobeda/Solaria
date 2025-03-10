#include "Platform.h"

Platform::Platform() {
	TePlat.loadFromFile("Assets/Carre-Rouge.jpg");
	SpPlat.setTexture(TePlat);
	SpPlat.setPosition({ 500, 500 });
}


void Platform::draw(RenderWindow& window) {
	window.draw(SpPlat);
}

void Platform::update(float deltatime) {

}