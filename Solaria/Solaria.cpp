#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "Platform.h"
#include "Player.hpp"

using namespace sf;
using namespace std;

Ennemi test({20.f,20.f},10.f);

int main(int argc, char* argv[])
{
    Platform platform;
	Player player(100, 0.2f, 100);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (test.getBounds().intersects(player.getBounds())) {
            window.close();
        }

        test.update(0.01);
        player.update(1);

        
        window.clear();

		
		player.draw(window);
        test.draw(window);
        platform.draw(window);
	    
        
        window.display();


    }
}
