#pragma once
#include "Entity.h"
class Ennemi : public Entity
{

private:
    int hp = 3, i = 0;
    float speed = 50;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    sf::Vector2f positionP[2];
public:

    Ennemi(sf::Vector2f pos, int patrolRange);
    void update(float deltatime) override;
    void draw(sf::RenderWindow& window) override;
    ~Ennemi();

    FloatRect getBounds() {
        return sprite.getGlobalBounds();
    }
};
