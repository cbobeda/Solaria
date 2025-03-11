#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "MapLoader.h"
#include "Platform.h"
#include "Player.hpp"
#include "Menu.h"

using namespace sf;
using namespace std;

Ennemi test({20.f,20.f},10.f);

int main(int argc, char* argv[])
{
	Player player(100, 20.f, 100);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");

    float deltaTime;
    View view = window.getView();
    Menu menu(window);
    Clock clock;

    MapLoader mapLoader;
    
    bool isPause = false;
    bool gameOver = false;
    bool win = false;
    bool isOptions = false;

    //menu.menuDisplay(window, 0);
    
    while (window.isOpen())
    {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.key.code == Keyboard::Escape)
            {
                isPause = !isPause;
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
        player.update(deltaTime);

        
        window.clear();

		
		player.draw(window);
        test.draw(window);
	    mapLoader.draw(window);
        
        window.display();


    }
}
