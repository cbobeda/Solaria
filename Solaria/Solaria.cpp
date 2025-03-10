#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"

using namespace sf;
using namespace std;

Ennemi test({20.f,20.f}, 200);

int main(int argc, char* argv[])
{
    
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
	while (window.isOpen())
	{
		test.update(0.01);
		window.clear();
		test.draw(window);
		window.display();
        
	}
}
