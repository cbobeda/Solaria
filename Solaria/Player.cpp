#include "Player.hpp"
#include "Platform.h"


Player::Player(int health, float aspeed, int aenergy) : hp(health), speed(aspeed), energy(aenergy), jump(false), initialY(0.f), initialX(0.f), maxJumpHeight(350.f)
{
	if (!playerTexture.loadFromFile("player.png"))
	{
		cout << "Error loading player texture" << endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	playerPosition = Vector2f(200.f, 300.f);
	playerSprite.setPosition(playerPosition);
	playerSprite.setScale(1.5f, 1.5f);
	FloatRect playerBounds = playerSprite.getGlobalBounds();

	if (!energyTexture.loadFromFile("Energie-Sheet.png"))
	{
		cout << "Error loading energy texture" << endl;
	}
	energySprite.setTexture(energyTexture);
	energySprite.setTextureRect(sf::IntRect(0, 0, 39, 38));
	energySprite.setScale(3.f, 3.f);
	energySprite.setPosition(25.f, 100.f);
	
}

void Player::draw(RenderWindow& window)
{
	window.draw(playerSprite);
	window.draw(energySprite);
}

void Player::update(float deltatime, std::vector<std::shared_ptr<Tiles>>& platforms, Event& event)
{

	if (watchanime.getElapsedTime().asSeconds() > 0.5f) {
		IntRect newRect = playerSprite.getTextureRect();
		newRect.left += 64;
		if (newRect.left >= 256) { newRect.left -= 256; }
		playerSprite.setTextureRect(newRect);
		watchanime.restart();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) && !jump && energy >= 1)
	{
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= jumpCooldown.getElapsedTime().asSeconds())
		{
			jump = true;
			initialY = playerSprite.getPosition().y;
			energy -= 1;
			jumpCooldown.restart();
		}
	}

	if (jump)
	{
		if (playerSprite.getPosition().y > initialY - maxJumpHeight)
		{
			playerSprite.move(0, -speed * 0.5f);
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
		if (plat->sprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
		{

			if (plat->sprite.getPosition().y < playerSprite.getPosition().y)
			{
				hasToMoveDown = true;
			}
			else
			{
				playerSprite.setPosition(playerSprite.getPosition().x, plat->sprite.getPosition().y - 95);
				hasToMoveDown = false;
			}
		}
	}
	if (hasToMoveDown)
	{
		playerSprite.move(0, speed * deltatime * 5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		playerSprite.move(-speed * deltatime, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && Keyboard::isKeyPressed(Keyboard::LShift) && energy >= 1) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerSprite.getPosition().x;
			playerSprite.move(-100, 0);
			energy -= 1;
			dashCooldown.restart();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerSprite.move(speed * deltatime, 0);
	}

	if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift) && energy >= 1) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerSprite.getPosition().x;
			playerSprite.move(100, 0);
			energy -= 1;
			dashCooldown.restart();
		}
	}

	IntRect newRect = energySprite.getTextureRect();
	newRect.left = 39 * energy;
	if (newRect.left >= 585) { newRect.left -= 585; }
	energySprite.setTextureRect(newRect);

	if (energyreload.getElapsedTime().asSeconds() > 4.f) {
		energy += 1;
		energyreload.restart();
	}
}

Vector2f Player::getPosition() const {
	return playerPosition;
}



