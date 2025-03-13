#include "Ennemi.h"

Ennemi::Ennemi(sf::Vector2f pos, int patrolRange)
{
    positionP[0] = {pos.x, pos.y};
    positionP[1] = {pos.x + patrolRange, pos.y};
    texture.loadFromFile("ennemi.png");
    sprite.setTexture(texture);
    sprite.setScale(2.f, 2.f);
    sprite.setPosition(pos);
}

void Ennemi::update(float deltatime)
{
    {
        if (i >= 2)
        {
            i = 0;
            return;
        }

    
        if (std::abs(sprite.getPosition().x - positionP[i].x) > 1.0f)
        {
            float dirX = (positionP[i].x > sprite.getPosition().x) ? 1.0f : -1.0f;
            sprite.move(dirX * (16.f / 9.f) * speed * deltatime, 0);
        }

    
        if (std::abs(sprite.getPosition().y - positionP[i].y) > 1.0f)
        {
            float dirY = (positionP[i].y > sprite.getPosition().y) ? 1.0f : -1.0f;
            sprite.move(0, dirY * speed * deltatime);
        }

    
        if (std::abs(sprite.getPosition().x - positionP[i].x) <= 1.0f &&std::abs(sprite.getPosition().y - positionP[i].y) <= 1.0f)
        {
            i++;
            if (i >= 2)
            {
                i = 0;
            }
        }
    }
}

void Ennemi::draw(RenderWindow& window)
{
    window.draw(sprite);
}

Ennemi::~Ennemi()
{
    
}
