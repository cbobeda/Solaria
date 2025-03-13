#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 15;
const int CELL_SIZE = 40;

class Grid {
public:
    vector<vector<int>> grid;

    Grid();
    void draw(RenderWindow& window);
};

#endif