#include "Player.hpp"
#include "Platform.h"

Player::Player(int health, float aspeed, int aenergy) : hp(health), speed(aspeed), energy(aenergy), jump(false), initialY(0.f), initialX(0.f), maxJumpHeight(350.f)
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
    if (jump && playerPosition.y <= initialY - maxJumpHeight) {
        jump = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::Space) && !jump)
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
	for (auto& plat: platforms)
	{
		if (plat && !plat->platBounds.intersects(playerSprite.getGlobalBounds()))
		{
			playerPosition.y += speed * deltatime;
		}
		/*else if (plat->platBounds.getPosition().y > playerSprite.getPosition().y)
		{
			playerPosition.y += speed * deltatime;
		}*/
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		playerPosition.x -= speed * deltatime;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && Keyboard::isKeyPressed(Keyboard::LShift)) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerPosition.x;
			playerPosition.x -= initialX + 50;
			dashCooldown.restart();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerPosition.x += speed * deltatime;
	}

	if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerPosition.x;
			playerPosition.x += initialX + 50;
			dashCooldown.restart();
		}
	}

	playerSprite.setPosition(playerPosition);
}





