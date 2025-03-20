#include "Winitem.h"

Winitem::Winitem(Vector2f position, Player* player) : player(player)
{
	if (!winitemTexture.loadFromFile("assets/winitem.png"))
	{
		cout << "Error loading winitem texture" << endl;
	}
	winitemSprite.setTexture(winitemTexture);
	winitemSprite.setPosition(position);
	winitemSprite.setScale(0.2f, 0.2f);
}

void Winitem::draw(RenderWindow& window)
{
	window.draw(winitemSprite);
}

void Winitem::update(float deltatime)
{
	FloatRect winitemBounds = winitemSprite.getGlobalBounds();
	FloatRect playerBounds = player->playerSprite.getGlobalBounds();
	isWinning = false;
	if (winitemBounds.intersects(playerBounds))
	{
		cout << "You win!" << endl; //inserer eventuel ecran de victoire
		isWinning = true;
	}
}

Winitem::~Winitem()
{
}