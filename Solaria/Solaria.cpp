#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Whale-s-revenge", sf::Style::None);
	while (window.isOpen())
	{
        while (window.isOpen())
        {
            window.clear();
            window.display();
        }
	}
}
