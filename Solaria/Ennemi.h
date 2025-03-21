#pragma once
#include "Entity.h"
#include "Player.hpp"
class Ennemi : public Entity
{

private:
	Player* player;
    int hp = 3, i = 0;
    float speed = 50;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    sf::Vector2f positionP[2];

    //Music robotTakingDamage;
    //Music robotDying;

	IntRect ennemiRect;

	sf::Clock watchanime;
public:
	sf::Clock attackclock;
    Ennemi(sf::Vector2f pos, int patrolRange, Player* player);
    void update(float deltatime) override;
    void draw(sf::RenderWindow& window) override;
    ~Ennemi();
};
