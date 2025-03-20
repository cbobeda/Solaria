#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "FlyingEnemy.h"
#include "Taupe.h"
#include "Platform.h"
#include "MapLoader.h"
#include "Player.hpp"
#include "Menu.h"
#include "ClassTiles/GroundTile.h"
#include "ClassTiles/UndergroundTileDown.h"
#include "ClassTiles/DirtTile.h"



using namespace sf;
using namespace std;


int main(int argc, char* argv[])
{
    MapLoader mapLoader;
    
    
	

    RenderWindow window(VideoMode(1920, 1080), "Solaria",Style::Fullscreen);
    
    std::vector<std::shared_ptr<Tiles>> currentMap;
    
    float deltaTime;
    View view = window.getDefaultView();
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

            for (auto& ennemi : mapLoader.ennemies)
            {
                ennemi->update(deltaTime);
            }
            mapLoader.player.update(deltaTime,currentMap,window, event);
            mapLoader.winitem->update(deltaTime);
            for (auto& taupe : mapLoader.taupes)
            {
                taupe->update(deltaTime);
            }
            for (auto& fly :mapLoader.flyingEnemies)
            {
                fly->setPlayerPosition(mapLoader.player.playerSprite.getPosition());
                fly->update(deltaTime);
            }
            

            if (mapLoader.winitem->isWinning)
            {
                win = true;
            }
            
            window.clear();
            window.setView(view);
            mapLoader.draw(window);
            for (auto& fly :mapLoader.flyingEnemies)
            {
                fly->draw(window);
            }
            for (auto& ennemi : mapLoader.ennemies)
            {
                ennemi->draw(window);
            }
            for (auto& taupe : mapLoader.taupes)
            {
                taupe->draw(window);
            }
            if (mapLoader.player.playerSprite.getPosition().x > 960)
            {
                view.setCenter(mapLoader.player.playerSprite.getPosition().x,540);
            }
            mapLoader.player.grapin(window, currentMap,view, deltaTime);
            mapLoader.player.draw(window);
            mapLoader.mapLoaded = true;
        }

        
        
        window.display();


    }
    return 0;
}
