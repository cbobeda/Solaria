#include "FlyingEnemy.h"

FlyingEnemy::FlyingEnemy(Vector2f startPos, float radiusDetect) {
    if (!texture.loadFromFile("chatMoche.png")) {
        cerr << "Erreur de chargement de la texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(startPos);
    position = startPos;
    detectionRadius = radiusDetect;
    currentState = PATROL;
}

void FlyingEnemy::patrol()
{
    static int currentWaypoint = 0;
    static sf::Vector2f waypoints[4] = { sf::Vector2f(400, 300), sf::Vector2f(1000, 300) };
    sf::Vector2f target = waypoints[currentWaypoint];
    sf::Vector2f direction = target - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 5.0f) {
        currentWaypoint = (currentWaypoint + 1) % 2;
    }
    else {
        direction /= distance;
        position += direction * 0.05f;
    }
    sprite.setPosition(position);
}

void FlyingEnemy::chase(Vector2f playerPos)
{
    sf::Vector2f direction = playerPos - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance;
        position += direction * 0.05f;
    }

    sprite.setPosition(position);
}

void FlyingEnemy::search(Vector2f lastPlayerPos, float deltaTime) {
    static float searchTimer = 0.0f;
    static sf::Vector2f searchDirection;

    if (searchTimer == 0.0f) {
        searchDirection = sf::Vector2f(rand() % 2 == 0 ? -1 : 1, rand() % 2 == 0 ? -1 : 1);
        searchDirection /= std::sqrt(searchDirection.x * searchDirection.x + searchDirection.y * searchDirection.y);
    }

    searchTimer += deltaTime;
    if (searchTimer < 10.0f) {
        position += searchDirection * 5.f * deltaTime;
    }
    else {
        searchTimer = 0.0f;
        currentState = PATROL;
    }

    float distance = std::sqrt((lastPlayerPos.x - position.x) * (lastPlayerPos.x - position.x) + (lastPlayerPos.y - position.y) * (lastPlayerPos.y - position.y));
    if (distance < detectionRadius) {
        searchTimer = 0.0f;
    }

    sprite.setPosition(position);
}

bool FlyingEnemy::detectPlayer(Vector2f playerPos) {
    float distance = std::sqrt((playerPos.x - position.x) * (playerPos.x - position.x) + (playerPos.y - position.y) * (playerPos.y - position.y));
    return distance <= detectionRadius;
}

void FlyingEnemy::update(float deltatime) {
    switch (currentState) {
    case PATROL:
        patrol();
        if (detectPlayer(playerPosition)) currentState = CHASE;
        break;

    case CHASE:
        chase(playerPosition);
        if (!detectPlayer(playerPosition)) {
            lastPlayerPosition = playerPosition;
            currentState = SEARCH;
        }
        break;

    case SEARCH:
        search(lastPlayerPosition, deltatime);
        break;
    }
}

void FlyingEnemy::setPlayerPosition(Vector2f playerPos) {
    playerPosition = playerPos;
}

void FlyingEnemy::draw(RenderWindow& window) {
    window.draw(sprite);
}

FlyingEnemy::~FlyingEnemy()
{

}