#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"
#include "Platform.h"

using namespace sf;
using namespace std;



int main(int argc, char* argv[])
{
    
    RenderWindow window(VideoMode(1620, 1080), "Solaria");

    Platform platform;

	while (window.isOpen())
	{
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }

        }


        window.clear();
        platform.draw(window);
        window.display();
	}
}
