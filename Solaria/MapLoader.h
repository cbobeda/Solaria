#pragma once
#include "Platform.h"
#include "vector"
#include <fstream>

class MapLoader
{

private:
    string line;
    string currentLevel = "";
    std::vector<std::unique_ptr<Platform>> platforms;
    std::vector<string> map;
public:
    MapLoader();
    void setCurrentLevel (string newlevel);
    const std::vector<std::unique_ptr<Platform>>& getCurrentMap();
    void draw(RenderWindow& window);
    ~MapLoader();
    
};
