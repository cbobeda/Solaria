#include "Grid.h"

using namespace std;
using namespace sf;

Grid::Grid() {
    grid.resize(GRID_HEIGHT, vector<int>(GRID_WIDTH, 0));

    // Définition de quelques obstacles
    for (int i = 5; i < 15; i++) {
        grid[7][i] = 1;
    }
}

void Grid::draw(RenderWindow& window) {

}