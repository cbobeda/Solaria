#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Entity {
public:

	virtual void draw(RenderWindow& window) = 0;
	virtual void update(float deltatime) = 0;
};