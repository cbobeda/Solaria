#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


int main(int argc, char* argv[])
{
    
    RenderWindow window(VideoMode(1500, 500), "Solaria");
	while (window.isOpen())
	{
        while (window.isOpen())
        {
            window.clear();
            window.display();
        }
	}
}
