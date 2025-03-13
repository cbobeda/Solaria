#include "Taupe.h"

Taupe::Taupe(sf::Vector2f pos)
{
	taupeTexture.loadFromFile("taupe.jpg");
	taupeSprite.setTexture(taupeTexture);
	taupeSprite.setScale(0.1f, 0.1f);
	taupeSprite.setPosition(pos);

}

void Taupe::update(float deltatime)
{
	currentpos = taupeSprite.getPosition();
	maxY = currentpos.y + 50;
	minY = currentpos.y - 50;

	if (digging == false) {

	}

	if (digging == true) {
		if (currentpos.y < maxY) {
			Taupe::taupeSprite.move(0, (currentpos.y + 1 * speed * deltatime));
		}
		else if (currentpos.y > minY) {
			Taupe::taupeSprite.move(0, (currentpos.y - 1 * speed * deltatime));
		}
		
	}
}

void Taupe::draw(sf::RenderWindow& window)
{
	window.draw(taupeSprite);
}

Taupe::~Taupe()
{
}