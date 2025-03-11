#include "Player.hpp"
#include "Platform.h"

Player::Player(int health, float aspeed, int aenergy, Platform* plat) : hp(health), speed(aspeed), energy(aenergy), platform(plat), jump(false), initialY(0.f), maxJumpHeight(350.f)
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
    if (jump && playerPosition.y <= initialY - maxJumpHeight) {
        jump = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::Space) && !jump && platform && platform->platBounds.intersects(playerSprite.getGlobalBounds()))
    {
        float currentTime = Clock().getElapsedTime().asSeconds();

        if (1 <= jumpCooldown.getElapsedTime().asSeconds())
        {
            jump = true;
            initialY = playerPosition.y;
			jumpCooldown.restart();
        }
    }

    if (jump)
    {
        if (playerPosition.y > initialY - maxJumpHeight)
        {
            playerPosition.y -= speed * 1.5f;
        }
        else
        {
            jump = false;
        }
    }
	/*for(auo& plat: platforms)*/
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





