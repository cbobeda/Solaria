#ifndef NODE_H
#define NODE_H

#include <SFML/System/Vector2.hpp>

using namespace sf;

class Node {
public:
    Vector2i position;
    int gCost, hCost, fCost;
    Node* parent;

    Node(Vector2i pos);
    void calculateCosts(Vector2i endPos, int newG);
    int calculateHeuristic(Vector2i endPos);
};

#endif