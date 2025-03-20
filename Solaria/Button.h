#ifndef BUTTON_H  
#define BUTTON_H  

#include <iostream>  
#include <SFML/Graphics.hpp>  

using namespace sf;  
using namespace std;  

class Button {  
public:  
   Button(const Texture& texture, const Vector2f& position);  

   void draw(RenderWindow& window);  
   bool isClicked(const RenderWindow& window, Event event) const;  
   void setPosition(const Vector2f& position);  
   void setTexture(const Texture& texture);
   void setTextureRect(const sf::IntRect& rect);

private:  
   Sprite buttonSprite;  
};  

#endif