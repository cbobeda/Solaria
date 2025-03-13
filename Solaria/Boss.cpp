#include "Boss.h"

Boss::Boss(int health) : hp(health) {
	TextBoss.loadFromFile("cercle-rouge.png");
	SpriteBoss.setTexture(TextBoss);
	SpriteBoss.setPosition({ 1700,20 });
}

void Boss::draw(RenderWindow& window) {
	window.draw(SpriteBoss);
}
void Boss::update(float deltatime) {
	if (isWaiting) {
		if (clock.getElapsedTime().asSeconds() >= pauseDuration) {
			isWaiting = false;
			clock.restart();
		}
	}
	else {

		if (SpriteBoss.getPosition().x >= righlimite ) {
			direction = -1;
			//isWaiting = true;
		}
		else if (SpriteBoss.getPosition().x <= leftlimite) {
			direction = 1;
			//isWaiting = true;
		}
		if (SpriteBoss.getPosition().x == righlimite || SpriteBoss.getPosition().x == leftlimite) {
			isWaiting = true;
			clock.restart();
		}	

		SpriteBoss.move(speed* direction* deltatime, 0);
	}
	

	

}

Boss::~Boss() {

}