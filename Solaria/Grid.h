#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int GRID_WIDTH = 500;
const int GRID_HEIGHT = 300;
const int CELL_SIZE = 40;

class Grid {
public:
    vector<vector<int>> grid;

    Grid();
    void draw(RenderWindow& window);
};

#endif