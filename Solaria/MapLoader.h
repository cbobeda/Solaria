#pragma once
#include "DirtTile.h"
#include "GroundTile.h"
#include "UndergroundTile.h"
#include "vector"
#include <fstream>

class MapLoader
{

private:
    string line;
    string currentLevel = "";
    std::vector<std::unique_ptr<Tiles>> platforms;
    std::vector<string> map;
public:
    MapLoader();
    void setCurrentLevel (string newlevel);
    std::vector<std::unique_ptr<Tiles>> getCurrentMap();
    void draw(RenderWindow& window);
    ~MapLoader();
    
};
