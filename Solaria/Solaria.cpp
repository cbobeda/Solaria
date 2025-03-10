#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"

using namespace sf;
using namespace std;



int main(int argc, char* argv[])
{
    
    RenderWindow window(VideoMode(1920, 1080), "Solaria");
	while (window.isOpen())
	{
		window.clear();
		window.display();
         
	}
}
