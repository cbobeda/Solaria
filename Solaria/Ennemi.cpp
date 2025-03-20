#include "Ennemi.h"

Ennemi::Ennemi(sf::Vector2f pos, int patrolRange, Player* player) : player(player)
{
    positionP[0] = {pos.x, pos.y};
    positionP[1] = {pos.x + patrolRange, pos.y};
    texture.loadFromFile("assets/ennemi.png");
    sprite.setTexture(texture);
    ennemiRect = sf::IntRect(0, 0, 38, 81);
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

		if (player->playerSprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
            if (attackclock.getElapsedTime().asSeconds() > 3.f)
            {
                attackclock.restart();
                player->getdamage();
            }
		}
    }
    if (watchanime.getElapsedTime().asSeconds() > 0.5f) {
        ennemiRect.left += 38;
        if (abs(ennemiRect.left) >= 114) { ennemiRect.left = 0; }
        sprite.setTextureRect(ennemiRect);
        watchanime.restart();
    }
}

void Ennemi::draw(RenderWindow& window)
{
    window.draw(sprite);
}

Ennemi::~Ennemi()
{
    
}
