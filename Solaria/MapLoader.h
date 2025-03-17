#pragma once
#include "ClassTiles/DirtTile.h"
#include "ClassTiles/GroundTile.h"
#include "ClassTiles/UndergroundTile.h"
#include "vector"
#include "Player.hpp"
#include <fstream>

class MapLoader
{

private:
    string line;
    string currentLevel = "";
    std::vector<std::unique_ptr<Tiles>> platforms;
    std::vector<string> map;
public:
    Player player;
    bool mapLoaded = false;
public:
    MapLoader();
    void setCurrentLevel (string newlevel);
    std::vector<std::unique_ptr<Tiles>> getCurrentMap();
    void mapClear();
    void draw(RenderWindow& window);
    ~MapLoader();
    
};
