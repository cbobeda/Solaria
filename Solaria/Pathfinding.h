#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Grid.h"
#include "Node.h"
#include <vector>

using namespace std;
using namespace sf;

class Pathfinding {
public:
    static std::vector<sf::Vector2i> findPath(Grid& grid, sf::Vector2i start, sf::Vector2i end);
};

#endif