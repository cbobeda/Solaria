#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "Platform.h"
#include "Player.hpp"
#include "Menu.h"
#include "GroundTile.h"
#include "UndergroundTile.h"
#include "DirtTile.h"

using namespace sf;
using namespace std;

Ennemi test({20.f,20.f},10.f);

int main(int argc, char* argv[])
{
    
    Platform platform;
	Player player(100, 0.2f, 100);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
	/*GroundTile ground({ 50.f, 200.f });*/
    /*UndergroundTile underground({ 50.f, 200.f });*/
	/*DirtTile dirt({ 50.f, 200.f });*/
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

        deltaTime = clock.restart().asSeconds();

        test.update(0.01);
        player.update(1);

        
        window.clear();

		
		player.draw(window);
        test.draw(window);
        platform.draw(window);
		/*ground.draw(window);*/
		/*underground.draw(window);*/
		/*dirt.draw(window);*/
	    
        
        window.display();


    }
    return 0;
}
