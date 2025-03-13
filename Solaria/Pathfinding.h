#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Grid.h"
#include "Node.h"
#include <vector>

using namespace std;
using namespace sf;

class Pathfinding {
public:
    static vector<Vector2i> findPath(Grid& grid, Vector2i start, Vector2i end);
};

#endif