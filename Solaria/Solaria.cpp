#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "FlyingEnemy.h"
#include "Platform.h"
#include "MapLoader.h"
#include "Player.hpp"
#include "Menu.h"
#include "GroundTile.h"
#include "UndergroundTile.h"
#include "DirtTile.h"

using namespace sf;
using namespace std;

Ennemi test({20.f,650.f},50.f);

int main(int argc, char* argv[])
{
    MapLoader mapLoader;
	Player player(100, 150.f, 100);
    FlyingEnemy flyingEnemy(Vector2f(400, 300), 200.0f);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");

    std::vector<std::unique_ptr<Tiles>> currentMap;
    
    float deltaTime;
    View view = window.getView();
    Menu menu(window);
    Clock clock;

    
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
        if (isPause)
        {
            menu.menuDisplay(window, 1);
            isPause = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (gameOver)
        {
            menu.menuDisplay(window, 2);
            gameOver = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (win)
        {
            menu.menuDisplay(window, 3);
            win = false;
            clock.restart();
            window.setView(view);
            continue;
        }
        if (isOptions)
        {
            menu.menuDisplay(window, 4);
            isOptions = false;
            clock.restart();
            window.setView(view);
            continue;
        }

           
        mapLoader.setCurrentLevel("map.txt");
        
        deltaTime = clock.restart().asSeconds();

        test.update(deltaTime);
        player.update(deltaTime,currentMap, window, event);
        
       

        flyingEnemy.setPlayerPosition(player.getPosition());
        flyingEnemy.update(deltaTime);
        
        window.clear();

		
		player.draw(window);

       
        player.grapin(window, currentMap, deltaTime);
        flyingEnemy.draw(window);
        test.draw(window);
	    mapLoader.draw(window);
        
        window.display();


    }
    return 0;
}
