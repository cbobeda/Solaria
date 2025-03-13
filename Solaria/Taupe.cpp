#include "Taupe.h"
#include <iostream>

Taupe::Taupe(sf::Vector2f pos, int moveRange)
{
    taupeTexture.loadFromFile("taupe.jpg");
    taupeSprite.setTexture(taupeTexture);
    taupeSprite.setScale(0.1f, 0.1f);
    taupeSprite.setPosition(pos);

    positionP[0] = pos;
    positionP[1] = { pos.x + moveRange, pos.y };
}

void Taupe::update(float deltatime)
{
    currentpos = taupeSprite.getPosition();

    if (!digging)
    {
        if (currentpos.y < positionP[0].y + digDepth)
        {
            taupeSprite.move(0, speed * deltatime);
        }
        else
        {
            digging = true;
            taupeSprite.setPosition(positionP[1].x, positionP[0].y - 100);
        }
    }
    else
    {
        if (currentpos.y < positionP[0].y)
        {
            taupeSprite.move(0, speed * deltatime);
        }
        else
        {
            digging = false;
        }
    }
}

void Taupe::draw(sf::RenderWindow& window)
{
    window.draw(taupeSprite);
}

Taupe::~Taupe()
{
}
