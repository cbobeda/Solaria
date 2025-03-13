#include "Missile.h"


Missile::Missile(Vector2f MissilePos) {
	TextMissile.loadFromFile("cercle-orange.jpg");
	SpMissile.setTexture(TextMissile);
	SpMissile.setPosition(MissilePos);
}

void Missile::FollowPlayer(Player player) {
	
	if (player.playerSprite.getPosition().x >= SpMissile.getPosition().x) {
		SpMissile.move(0.01f * speed, 0);
	}
	else if (player.playerSprite.getPosition().x <= SpMissile.getPosition().x) {
		SpMissile.move(-0.01f * speed, 0);
	}
	if (player.playerSprite.getPosition().y >= SpMissile.getPosition().y) {
		SpMissile.move(0, 0.01f * speed);
	}
	else if (player.playerSprite.getPosition().y <= SpMissile.getPosition().y) {
		SpMissile.move(0, -0.01f * speed);
	}
}

void Missile::update(float deltatime) {

}

void Missile::draw(RenderWindow& window) {
	window.draw(SpMissile);
}

Missile::~Missile() {

}