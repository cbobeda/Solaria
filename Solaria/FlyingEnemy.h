#ifndef FLYINGENEMY_H
#define FLYINGENEMY_H

#include "Entity.h"
#include "Player.hpp"
#include <cmath>

class FlyingEnemy : public Entity {
private:
    int hp = 3;
    Texture texture;
    Sprite sprite;
    Vector2f playerPosition;

public:
    Vector2f position;
    CircleShape circle;
    Vector2f lastPlayerPosition;
    float detectionRadius;
    enum State { PATROL, CHASE, SEARCH };
    State currentState;

    FlyingEnemy(Vector2f startPos, float radiusDetect);
    void update(float deltatime) override;
    void draw(RenderWindow& window) override;

    bool detectPlayer(Vector2f playerPosition);
    void patrol();
    void chase(Vector2f playerPosition);
    void search(Vector2f lastPlayterPos, float deltatime);
    void setPlayerPosition(Vector2f playerPosition);
    ~FlyingEnemy();

};

#endif
