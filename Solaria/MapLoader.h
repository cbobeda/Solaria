#pragma once

#include "Ennemi.h"
#include "FlyingEnemy.h"
#include "Taupe.h"
#include "ClassTiles/DirtTile.h"
#include "ClassTiles/GroundTile.h"
#include "ClassTiles/UndergroundTile3Right.h"
#include "ClassTiles/UndergroundTile3Down.h"
#include "ClassTiles/UndergroundTile3Left.h"
#include "ClassTiles/UndergroundTile3Up.h"
#include "ClassTiles/UndergroundTileUp.h"
#include "ClassTiles/UndergroundTileUpLeft.h"
#include "ClassTiles/UndergroundTileUpRight.h"
#include "ClassTiles/UndergroundTileDown.h"
#include "ClassTiles/UndergroundTileDownLeft.h"
#include "ClassTiles/UndergroundTileDownRight.h"
#include "ClassTiles/UndergroundTileLeft.h"
#include "ClassTiles/UndergroundTileRight.h"
#include "vector"
#include "Player.hpp"
#include "Grid.h"
#include <fstream>

class MapLoader
{

private:
    string line;
    string currentLevel = "";
    Texture bgTexture;
    Sprite bgSprite;
    std::vector<std::shared_ptr<Tiles>> platforms;
    std::vector<string> map;
public:
    Player player;
    std::vector<std::shared_ptr<Ennemi>> ennemies;
    std::vector<std::shared_ptr<FlyingEnemy>> flyingEnemies;
    std::vector<std::shared_ptr<Taupe>> taupes;
    Grid grid;
    bool mapLoaded = false;
public:
    MapLoader();
    void setCurrentLevel (string newlevel);
    std::vector<std::shared_ptr<Tiles>> getCurrentMap();
    void draw(RenderWindow& window);
    ~MapLoader();
    
};
