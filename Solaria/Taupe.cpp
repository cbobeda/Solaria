#include "Taupe.h"
#include <iostream>

Taupe::Taupe(sf::Vector2f pos, int moveRange, Player* player): player(player)
{
    if (!taupeTexture.loadFromFile("assets/taupe.png"))
    {
        std::cerr << "Erreur de chargement de la texture taupe.png" << std::endl;
    }
    taupeRect = IntRect(0, 0, 74, 55);
    taupeSprite.setTexture(taupeTexture);
    taupeSprite.setScale(3.f, 3.f);
    taupeSprite.setPosition(pos);

    positionP[0] = {pos.x,pos.y - 50.f};
    positionP[1] = { pos.x + moveRange, pos.y};
}

void Taupe::update(float deltaTime)
{
    sf::Vector2f currentPos = taupeSprite.getPosition();


    if (!digging)
    {
        if (currentPos.y < positionP[0].y + digDepth)
        {
            taupeSprite.move(0, speed * deltaTime);
        }
        else
        {
            digging = true;
        }
    }
    else
    {
        if (currentPos.y < positionP[0].y)
        {
            taupeSprite.move(0, digSpeed * deltaTime);
        }
        else
        {
            digging = false;
        }

        taupeSprite.move(-lateralSpeed * deltaTime, 0);
    }
	if (player->playerSprite.getGlobalBounds().intersects(taupeSprite.getGlobalBounds()))
	{
	    if (attackclock.getElapsedTime().asSeconds() > 1.f)
	    {
	        attackclock.restart();
	        player->getdamage();
	    }
	}
    if (watchanime.getElapsedTime().asSeconds() > 0.2f) {
        taupeRect.left += 74;
        if (abs(taupeRect.left) >= 444) { taupeRect.left = 0; }
        taupeSprite.setTextureRect(taupeRect);
        watchanime.restart();
    }
}

void Taupe::draw(sf::RenderWindow& window)
{
    window.draw(taupeSprite);
}

Taupe::~Taupe()
{
}
