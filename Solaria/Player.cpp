#include "Player.hpp"

Player::Player(int health, float aspeed, int aenergy) : hp(health), speed(aspeed), energy(aenergy)
{
	if (!playerTexture.loadFromFile("player.png"))
	{
		cout << "Error loading player texture" << endl;
	}
	playerSprite.setTexture(playerTexture);
	playerPosition = Vector2f(960.f, 20.f);
	playerSprite.setPosition(playerPosition);
	playerSprite.setScale(1, 1);
}

void Player::draw(RenderWindow& window)
{
	window.draw(playerSprite);
}

void Player::update(float deltatime)
{
	
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		playerPosition.x -= speed * deltatime;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerPosition.x += speed * deltatime;
	}
	playerSprite.setPosition(playerPosition);
}





