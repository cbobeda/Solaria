#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Menu
{
private:

	Sprite mainMenuBGSprite;
	Sprite pauseMenuBGSprite;
	Sprite optionsMenuBGSprite;
	Sprite gameOverBGSprite;
	Sprite winBGSprite;
	Sprite titleTextSprite;
	Sprite gameOverTextSprite;
	Sprite winTextSprite;
	Sprite volumeTextSprite;
	Sprite volumeBarSprite;
	Sprite volumeCursorSprite;

	Texture mainMenuBGTexture;
	Texture pauseMenuBGTexture;
	Texture optionsMenuBGTexture;
	Texture gameOverBGTexture;
	Texture winBGTexture;
	Texture titleTextTexture;
	Texture gameOverTextTexture;
	Texture winTextTexture;
	Texture volumeTextTexture;

	Texture buttonPlayTexture;
	Texture buttonExitTexture;
	Texture buttonOptionsTexture;
	Texture buttonResumeTexture;
	Texture buttonReturnTexture;
	Texture volumeBarTexture;
	Texture volumeCursorTexture;

	Music tutorielMusic;
	Music levelOneMusic;
	Music levelTwoMusic;
	Music bossMusic;
	Music mainMenuMusic;
	Music winMusic;
	Music gameOverMusic;
	Music creditsMusic;
	
	
	
	vector<Button> buttons;

public:
	Menu(RenderWindow& window);

	void draw(RenderWindow& window);
	void menuDisplay(RenderWindow&, int type);
	int handleInput(const RenderWindow& window, Event event);
	void handleVolumeControl(const RenderWindow& window, Event event);
	void updateVolumeCursorPosition();
	bool isDraggingCursor;
	float volumeLevel;
};

#endif