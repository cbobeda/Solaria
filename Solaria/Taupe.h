#pragma once
#include "Entity.h"
#include "Player.hpp"
#include <SFML/Graphics.hpp>

class Taupe : public Entity
{
private:
    int hp = 1;
    float speed = 300.0f;
    float digDepth = 210.0f;
    float digSpeed = 300.0f;
	Player* player;
    sf::Texture taupeTexture;
    sf::Sprite taupeSprite;
    
    sf::Vector2f positionP[2];
    bool digging = false;
    float lateralSpeed = 80.0f;
   

public:
   
   
	sf::Clock attackclock; 
    Taupe(sf::Vector2f pos, int moveRange, Player* player);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void getDamage();
    ~Taupe();
};
