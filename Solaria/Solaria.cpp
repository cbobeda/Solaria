#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Ennemi.h"
#include "Platform.h"

using namespace sf;
using namespace std;



int main(int argc, char* argv[])
{
	Player player(100, 0.2f, 100);
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

		player.update(1);
		player.draw(window);

        
        window.display();


    }
}
