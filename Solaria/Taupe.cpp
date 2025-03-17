#include "Taupe.h"
#include <iostream>

Taupe::Taupe(sf::Vector2f pos, int moveRange)
{
    if (!taupeTexture.loadFromFile("taupe.jpg"))
    {
        std::cerr << "Erreur de chargement de la texture taupe.jpg" << std::endl;
    }

    taupeSprite.setTexture(taupeTexture);
    taupeSprite.setScale(0.1f, 0.1f);
    taupeSprite.setPosition(pos);

    positionP[0] = pos;
    positionP[1] = { pos.x + moveRange, pos.y };
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
}

void Taupe::draw(sf::RenderWindow& window)
{
    window.draw(taupeSprite);
}

Taupe::~Taupe()
{
}
