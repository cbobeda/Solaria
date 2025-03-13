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
	playerPosition = Vector2f(500.f, 300.f);
	playerSprite.setPosition(playerPosition);
	playerSprite.setScale(1.5f, 1.5f);
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	
}


void Player::draw(RenderWindow& window)
{
	window.draw(playerSprite);
}

void Player::update(float deltatime,std::vector<std::unique_ptr<Platform>>& platforms)
{

	if (watchanime.getElapsedTime().asSeconds() > 0.5f) {
		IntRect newRect = playerSprite.getTextureRect();
		newRect.left += 64;
		if (newRect.left >= 256) { newRect.left -= 256; }
		playerSprite.setTextureRect(newRect);
		watchanime.restart();
	}
    if (Keyboard::isKeyPressed(Keyboard::Space) && !jump)
    {
        float currentTime = Clock().getElapsedTime().asSeconds();

        if (1 <= jumpCooldown.getElapsedTime().asSeconds())
        {
            jump = true;
            initialY = playerSprite.getPosition().y;
			jumpCooldown.restart();
        }
    }

    if (jump)
    {
        if (playerSprite.getPosition().y > initialY - maxJumpHeight)
        {
            playerSprite.move(0,-speed);
        }
        else
        {
            jump = false;
        }
    }
	hasToMoveDown = true;
	for (auto& plat: platforms)
	{
		if (plat->SpPlat.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
		{
			
			if (plat->platBounds.getPosition().y < playerSprite.getPosition().y)
			{
				hasToMoveDown = true;
			}
			else
			{
				playerSprite.setPosition(playerSprite.getPosition().x,plat->platBounds.getPosition().y -95);
				hasToMoveDown = false;
			}
		}
	}
	if (hasToMoveDown)
	{
		playerSprite.move( 0,speed * deltatime * 5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		playerSprite.move(-speed * deltatime,0);
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
		playerSprite.move(speed * deltatime,0);
	}

	if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerPosition.x;
			playerPosition.x += initialX + 50;
			dashCooldown.restart();
		}
	}


}





