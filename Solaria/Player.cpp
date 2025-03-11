#include "Player.hpp"
#include "Platform.h"

Player::Player(int health, float aspeed, int aenergy) : hp(health), speed(aspeed), energy(aenergy)
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

void Player::update(float deltatime,std::vector<std::unique_ptr<Platform>>& platforms)
{
	for (auto& plat: platforms)
	{
		if (plat && !plat->platBounds.intersects(playerSprite.getGlobalBounds()))
		{
			playerPosition.y += speed * deltatime;
		}
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





