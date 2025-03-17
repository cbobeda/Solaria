#include "Grid.h"

using namespace std;
using namespace sf;

Grid::Grid() {
    grid.resize(GRID_HEIGHT, vector<int>(GRID_WIDTH, 0));

    // Définition de quelques obstacles
}

void Grid::draw(RenderWindow& window) {
    RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x] == 1) {
                cell.setFillColor(Color::Red);
            }
            else {
                cell.setFillColor(Color::Transparent);
            }
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            window.draw(cell);
        }
    }
}
