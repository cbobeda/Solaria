#pragma once
#include "Entity.h"

class Taupe : public Entity
{
private:
    int hp = 1;
    float speed = 100;
    float digDepth = 50;
    Vector2f currentpos;
    sf::Texture taupeTexture;
    sf::Sprite taupeSprite;
    sf::Vector2f positionP[2];
    bool digging = false;

public:
    Taupe(sf::Vector2f pos, int moveRange);
    void update(float deltatime) override;
    void draw(sf::RenderWindow& window) override;
    ~Taupe();
};
