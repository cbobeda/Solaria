#include "Grid.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;
using namespace sf;

Grid::Grid() {
    grid.resize(GRID_HEIGHT, vector<int>(GRID_WIDTH, 0));

    // Définition de quelques obstacles
    /*for (int i = 5; i < 15; i++) {
        grid[7][i] = 1;
    }*/
}

void Grid::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << endl;
        return;
    }

void Grid::draw(RenderWindow& window) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(Color::Black);

            if (grid[y][x] == 1) {
                cell.setFillColor(Color::Transparent);
            }
            else {
                cell.setFillColor(Color::Transparent);
            }

            window.draw(cell);
        }
    }
}

Cell& Grid::getCell(int x, int y) {
    return cells[y][x];
}