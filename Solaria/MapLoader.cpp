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
            std::cout << line << std::endl;
        }
    }
    for (int y = 0; y<map.size(); y++) {
        std::cout << line << std::endl;
        std::cout << "z" << std::endl;

        for (int x = 0; x < map[y].size(); x++)
        {
            if (map[y][x] == 'x')
            {
                platforms.push_back(std::move(std::make_unique<Platform>(Vector2i{x * 40, y * 40})));
            }
        }
    }
}

const std::vector<std::unique_ptr<Platform>>& MapLoader::getCurrentMap()
{
    return platforms;
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
