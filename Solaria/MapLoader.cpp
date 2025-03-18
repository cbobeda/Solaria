#include "MapLoader.h"

MapLoader::MapLoader()
{
}


void MapLoader::setCurrentLevel(string newlevel)
{
    if (newlevel != currentLevel)
    {
        currentLevel = newlevel;
        std::cout << "currentLevel: " << newlevel << std::endl;
        std::ifstream fichier(currentLevel, std::ios::in);
        while (std::getline(fichier, line)) {
            std::cout << line << std::endl;
            map.push_back(line);
        }

        
        for (int y = 0; y<map.size(); y++) {

            for (int x = 0; x < map[y].size(); x++)
            {
                if (map[y][x] == 'x')
                {
                    platforms.push_back(std::make_shared<DirtTile>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'c')
                {
                    platforms.push_back(std::make_shared<GroundTile>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'p' && !mapLoaded)
                {
                    player.playerSprite.setPosition(x * 40.f, y * 40.f);
                }
                if (map[y][x] == 'w')
                {
                    platforms.push_back(std::make_shared<UndergroundTile>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'l')
                {
                    platforms.push_back(std::make_shared<UndergroundTileLeft>(Vector2f{x * 40.f, y * 40.f}));
                }
            }
        }
    }
}
std::vector<std::shared_ptr<Tiles>> MapLoader::getCurrentMap()
{
    return platforms;
}


void MapLoader::draw(RenderWindow& window)
{
    int i = 0;
    for (auto& platform : platforms)
    {
        i++;
        std::cout << i  << std::endl;
        platform->draw(window);
    }
}

MapLoader::~MapLoader()
{
    
}
