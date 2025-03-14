#include "Boss.h"
#include "Platform.h"

Boss::Boss(int health) : hp(health), jump(false), initialY(0.f), initialX(0.f), maxJumpHeight(350.f) {
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

		if (Keyboard::isKeyPressed(Keyboard::Space) && !jump)
		{
			float currentTime = Clock().getElapsedTime().asSeconds();

			if (1 <= jumpCooldown.getElapsedTime().asSeconds())
			{
				jump = true;
				initialY = SpriteBoss.getPosition().y;
				jumpCooldown.restart();
			}
		}

		if (jump)
		{
			if (SpriteBoss.getPosition().y > initialY - maxJumpHeight)
			{
				SpriteBoss.move(0, -speed * 0.5f);
			}
			if (sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "endJump" << std::endl;
					jump = false;
				}
			}
			else
			{
				jump = false;
			}
		}
		hasToMoveDown = true;
		for (auto& plat : platforms)
		{
			if (plat->sprite.getGlobalBounds().intersects(SpriteBoss.getGlobalBounds()))
			{

				if (plat->sprite.getPosition().y < SpriteBoss.getPosition().y)
				{
					hasToMoveDown = true;
				}
				else
				{
					SpriteBoss.setPosition(SpriteBoss.getPosition().x, plat->sprite.getPosition().y - 95);
					hasToMoveDown = false;
				}
			}
		}
		if (hasToMoveDown)
		{
			SpriteBoss.move(0, speed * deltatime * 5.f);
		}

	}

		SpriteBoss.move(speed* direction* deltatime, 0);
	}
	


Boss::~Boss() {

}