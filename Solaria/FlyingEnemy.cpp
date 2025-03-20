#include "FlyingEnemy.h"

FlyingEnemy::FlyingEnemy(Vector2f startPos, float radiusDetect, Grid* grid, Player* player) : grid(grid) {
    if (!texture.loadFromFile("assets/Enemy/chatMoche.png")) {
        cerr << "Erreur de chargement de la texture" << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(startPos);
    position = startPos;
    detectionRadius = radiusDetect;
    currentState = PATROL;
    pathIndex = 0;
}

void FlyingEnemy::patrol() {
    static Vector2i waypoints[2] = { Vector2i(5, 5), Vector2i(18, 5) };
    static int currentWaypoint = 0;

    if (path.empty() || pathIndex >= path.size()) {
        Vector2i startPos(static_cast<int>(position.x / CELL_SIZE), static_cast<int>(position.y / CELL_SIZE));
        Vector2i endPos = waypoints[currentWaypoint];
        path = Pathfinding::findPath(*grid, startPos, endPos);
        pathIndex = 0;
        currentWaypoint = (currentWaypoint + 1) % 2;
    }

    if (!path.empty() && pathIndex < path.size()) {
        Vector2f target(path[pathIndex].x * CELL_SIZE, path[pathIndex].y * CELL_SIZE);
        Vector2f direction = target - position;
        float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance < 5.0f) {
            pathIndex++;
        }
        else {
            direction /= distance;
            position = position + direction * 5.f;
        }
        sprite.setPosition(position);
    }
}

void FlyingEnemy::chase(Vector2f playerPos) {
    Vector2f direction = playerPos - position;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance;
        position += direction * 5.f;
    }

	if (distance <= 5.0f) {
        if (attackclock.getElapsedTime().asSeconds() > 5.f) {
            attackclock.restart();
            player->getdamage();
        }
	}

    sprite.setPosition(position);
}

void FlyingEnemy::search(Vector2f lastPlayerPos, float deltaTime) {
    static float searchTimer = 0.0f;

    searchTimer += deltaTime;
    if (searchTimer < 1.0f) {
        return;
    }

    if (path.empty() || pathIndex >= path.size()) {
        Vector2i startPos(static_cast<int>(position.x / CELL_SIZE), static_cast<int>(position.y / CELL_SIZE));
        Vector2i endPos(static_cast<int>(lastPlayerPos.x / CELL_SIZE), static_cast<int>(lastPlayerPos.y / CELL_SIZE));
        path = Pathfinding::findPath(*grid, startPos, endPos);
        pathIndex = 0;
    }

    if (!path.empty() && pathIndex < path.size()) {
        Vector2f target(path[pathIndex].x * CELL_SIZE, path[pathIndex].y * CELL_SIZE);
        Vector2f direction = target - position;
        float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance < 5.0f) {
            pathIndex++;
        }
        else {
            direction /= distance;
            position += direction * 5.f;
        }
        sprite.setPosition(position);
    }

    if (pathIndex >= path.size()) {
        searchTimer = 0.0f;
        currentState = PATROL;
    }
}

bool FlyingEnemy::detectPlayer(Vector2f playerPos) {
    float distance = sqrt((playerPos.x - position.x) * (playerPos.x - position.x) + (playerPos.y - position.y) * (playerPos.y - position.y));
    return distance <= detectionRadius;
}

void FlyingEnemy::update(float deltatime) {
    switch (currentState) {
    case PATROL:
        patrol();
        if (detectPlayer(playerPosition)) {
            currentState = CHASE;
        }
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
        if (detectPlayer(playerPosition)) {
            currentState = CHASE;
        }
        break;
    }
}

void FlyingEnemy::setPlayerPosition(Vector2f playerPos) {
    playerPosition = playerPos;
}

void FlyingEnemy::draw(RenderWindow& window) {
    window.draw(sprite);
}

FlyingEnemy::~FlyingEnemy() {
}
