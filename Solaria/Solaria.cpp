#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "FlyingEnemy.h"
#include "Platform.h"
#include "MapLoader.h"
#include "Player.hpp"
#include "Menu.h"
#include "ClassTiles/GroundTile.h"
#include "ClassTiles/UndergroundTile.h"
#include "ClassTiles/DirtTile.h"
#include "Grid.h"

using namespace sf;
using namespace std;

Ennemi test({20.f,650.f},50.f);

int main(int argc, char* argv[])
{
    MapLoader mapLoader;
    Grid grid;
    
	Player player(100, 150.f, 100);
    FlyingEnemy flyingEnemy(Vector2f(300, 300), 130.0f, &grid);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
    
    std::vector<std::shared_ptr<Tiles>> currentMap;
    
    float deltaTime;
    View view = window.getView();
    Menu menu(window);
    Clock clock;

    int typeMenu = 0;
    bool isMainMenu = true;
    bool isPause = false;
    bool gameOver = false;
    bool win = false;
    bool isOptions = false;

    
    menu.menuDisplay(window, 0);

    while (window.isOpen())
    {
        Event event;
        currentMap = mapLoader.getCurrentMap();
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    isPause = !isPause;
                }
            }
        }
        if (isMainMenu)
        {
            typeMenu = 0;
            menu.menuDisplay(window, typeMenu);
            isMainMenu = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        else if (isPause)
        {
            typeMenu = 1;
            menu.menuDisplay(window, typeMenu);
            isPause = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        else if (gameOver)
        {
            typeMenu = 2;
            menu.menuDisplay(window, typeMenu);
            gameOver = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        else if (win)
        {
            typeMenu = 3;
            menu.menuDisplay(window, typeMenu);
            win = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        else if (isOptions)
        {
            typeMenu = 4;
            menu.menuDisplay(window, typeMenu);
            isOptions = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        else if (!isMainMenu && !isPause && !gameOver && !win && !isOptions)
        {
            mapLoader.setCurrentLevel("map.txt");
            deltaTime = clock.restart().asSeconds();

            test.update(deltaTime);
            mapLoader.player.update(deltaTime,currentMap, event);

            flyingEnemy.setPlayerPosition(mapLoader.player.getPosition());
            flyingEnemy.update(deltaTime);
        
            window.clear();

		
            mapLoader.player.draw(window);
            flyingEnemy.draw(window);
            test.draw(window);
            mapLoader.draw(window);
            mapLoader.mapLoaded = true;
        }

        
        
        window.display();


    }
    return 0;
}
