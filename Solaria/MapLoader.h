#pragma once
#include "ClassTiles/DirtTile.h"
#include "ClassTiles/GroundTile.h"
#include "ClassTiles/UndergroundTile.h"
#include "ClassTiles/UndergroundTileLeft.h"
#include "vector"
#include "Player.hpp"
#include <fstream>

class MapLoader
{

private:
    string line;
    string currentLevel = "";
    std::vector<std::shared_ptr<Tiles>> platforms;
    std::vector<string> map;
public:
    Player player;
    bool mapLoaded = false;
public:
    MapLoader();
    void setCurrentLevel (string newlevel);
    std::vector<std::shared_ptr<Tiles>> getCurrentMap();
    void draw(RenderWindow& window);
    ~MapLoader();
    
};
