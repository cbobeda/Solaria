#include "MapLoader.h"

MapLoader::MapLoader()
{
}


void MapLoader::setCurrentLevel(string newlevel)
{
    if (newlevel != currentLevel)
    {
        currentLevel = newlevel;
        std::ifstream fichier(currentLevel, std::ios::in);
        while (std::getline(fichier, line)) {
            map.push_back(line);
        }
    }
    for (int y = 0; y<map.size(); y++) {

        for (int x = 0; x < map[y].size(); x++)
        {
            if (map[y][x] == 'x')
            {
                platforms.push_back(std::move(std::make_unique<DirtTile>(Vector2f{x * 40.f, y * 40.f})));
            }
            if (map[y][x] == 'c')
            {
                platforms.push_back(std::move(std::make_unique<GroundTile>(Vector2f{x * 40.f, y * 40.f})));
            }
            if (map[y][x] == 'p' && !mapLoaded)
            {
                player.playerSprite.setPosition(x * 40.f, y * 40.f);
            }
            if (map[y][x] == 'w')
            {
                platforms.push_back(std::move(std::make_unique<UndergroundTile>(Vector2f{x * 40.f, y * 40.f})));
            }
        }
    }
}
std::vector<std::unique_ptr<Tiles>> MapLoader::getCurrentMap()
{
    return std::move(platforms);
}

void MapLoader::mapClear()
{
    platforms.clear();
}

void MapLoader::draw(RenderWindow& window)
{
    for (auto& platform : platforms)
    {
        platform->draw(window);
    }
}

MapLoader::~MapLoader()
{
    
}
