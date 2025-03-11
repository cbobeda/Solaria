#include "Player.hpp"
#include "Platform.h"

Player::Player(int health, float aspeed, int aenergy, Platform* plat) : hp(health), speed(aspeed), energy(aenergy), platform(plat)
{
	if (!playerTexture.loadFromFile("player.png"))
	{
		cout << "Error loading player texture" << endl;
	}
	playerSprite.setTexture(playerTexture);
	playerPosition = Vector2f(500.f, 300.f);
	playerSprite.setPosition(playerPosition);
	playerSprite.setScale(1, 1);
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	
}


void Player::draw(RenderWindow& window)
{
	window.draw(playerSprite);
}

void Player::update(float deltatime)
{

	if (platform && !platform->platBounds.intersects(playerSprite.getGlobalBounds()))
	{
		playerPosition.y += speed * deltatime;
	}
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





