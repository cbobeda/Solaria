#ifndef GRID_H
#define GRID_H

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int GRID_WIDTH = 1000;
const int GRID_HEIGHT = 1900;
const int CELL_SIZE = 40;

struct Cell {
    bool walkable;
    Vector2f position;
    RectangleShape shape;
};

class Grid {
public:

    Grid();
    void loadFromFile(const string& filename);
    void draw(RenderWindow& window);
    bool isObstacle(const Vector2f& position) const;
    Cell& getCell(int x, int y);
    vector<vector<int>> grid;

private:
    vector<vector<Cell>> cells;
};

#endif