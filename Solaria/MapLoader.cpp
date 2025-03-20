#include "MapLoader.h"




MapLoader::MapLoader()
{
    if (!bgTexture.loadFromFile("assets/background/level1.png"))
    {
        std::cerr << "Failed to load background texture" << std::endl;
    }
    winitem = std::make_shared<Winitem>(Vector2f(100000,100000),&player);
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(6.75, 6.75);
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
                if (map[y][x] == 'g')
                {
                    platforms.push_back(std::make_shared<DirtTile>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'c')
                {
                    platforms.push_back(std::make_shared<GroundTile>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'p' && !mapLoaded)
                {
                    player.playerPosition = { x * 40.f, y * 40.f };
                    player.playerSprite.setPosition(x * 40.f, y * 40.f);
                }
                if (map[y][x] == 'u')
                {
                    platforms.push_back(std::make_shared<UndergroundTileUp>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'd')
                {
                    platforms.push_back(std::make_shared<UndergroundTileDown>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'l')
                {
                    platforms.push_back(std::make_shared<UndergroundTileLeft>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'r')
                {
                    platforms.push_back(std::make_shared<UndergroundTileRight>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 't')
                {
                    platforms.push_back(std::make_shared<UndergroundTileUpLeft>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'b')
                {
                    platforms.push_back(std::make_shared<UndergroundTileUpRight>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'f')
                {
                    platforms.push_back(std::make_shared<UndergroundTileDownLeft>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'm')
                {
                    platforms.push_back(std::make_shared<UndergroundTileDownRight>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 's')
                {
                    platforms.push_back(std::make_shared<UndergroundTile3Up>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'y')
                {
                    platforms.push_back(std::make_shared<UndergroundTile3Down>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'k')
                {
                    platforms.push_back(std::make_shared<UndergroundTile3Right>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'n')
                {
                    platforms.push_back(std::make_shared<UndergroundTile3Left>(Vector2f{x * 40.f, y * 40.f}));
                }
                if (map[y][x] == 'w')
                {
                    winitem->winitemSprite.setPosition(x * 40.f, y * 40.f);
                }
                if (map[y][x] == '1')
                {
                    ennemies.push_back(std::make_shared<Ennemi>(Vector2f{x * 40.f, y * 40.f},10,&player));
                }
                if (map[y][x] == '2')
                {
                    flyingEnemies.push_back(std::make_shared<FlyingEnemy>(Vector2f{x * 40.f, y * 40.f},10,&grid,&player));
                }
                if (map[y][x] == '3')
                {
                    taupes.push_back(std::make_shared<Taupe>(Vector2f{x * 40.f, y * 40.f},10,&player));
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
    window.draw(bgSprite);
    for (auto& platform : platforms)
    {
        if (platform->sprite.getGlobalBounds().intersects(player.playerSprite.getGlobalBounds()))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.playerSprite.move(-player.speed,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                player.playerSprite.move(player.speed,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                player.playerSprite.move(0,player.speed);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                player.playerSprite.move(0,-player.speed);
            }
        }
        platform->draw(window);
    }
    winitem->draw(window);
}

MapLoader::~MapLoader()
{
    
}
