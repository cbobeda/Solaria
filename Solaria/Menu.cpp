#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
	
using namespace std;
using namespace sf;

Menu::Menu(RenderWindow& window) : isDraggingCursor(false), volumeLevel(100.0f)
{
	// Background du menu Principal
	mainMenuBGTexture.loadFromFile("MainMenuBG.png");
	mainMenuBGSprite.setTexture(mainMenuBGTexture);
	Vector2u windowSizeMainBG = window.getSize();
	Vector2u textureSizeMainBG = mainMenuBGTexture.getSize();

	float scaleMainBGX = static_cast<float>(windowSizeMainBG.x) / textureSizeMainBG.x;
	float scaleMainBGY = static_cast<float>(windowSizeMainBG.y) / textureSizeMainBG.y;

	// Background du menu Pause
	pauseMenuBGTexture.loadFromFile("PauseMenuBG.jpg");
	pauseMenuBGSprite.setTexture(pauseMenuBGTexture);
	Vector2u windowSizePauseBG = window.getSize();
	Vector2u textureSizePauseBG = pauseMenuBGTexture.getSize();

	float scalePauseBGX = static_cast<float>(windowSizePauseBG.x) / textureSizePauseBG.x;
	float scalePauseBGY = static_cast<float>(windowSizePauseBG.y) / textureSizePauseBG.y;

	// Background du menu Game Over
	gameOverBGTexture.loadFromFile("GameOverBG.png");
	gameOverBGSprite.setTexture(gameOverBGTexture);
	Vector2u windowSizeGameOverBG = window.getSize();
	Vector2u textureSizeGameOverBG = gameOverBGTexture.getSize();

	float scaleGameOverBGX = static_cast<float>(windowSizeGameOverBG.x) / textureSizeGameOverBG.x;
	float scaleGameOverBGY = static_cast<float>(windowSizeGameOverBG.y) / textureSizeGameOverBG.y;

	// Background du menu Win
	winBGTexture.loadFromFile("WinBG.png");
	winBGSprite.setTexture(winBGTexture);
	Vector2u windowSizeWinBG = window.getSize();
	Vector2u textureSizeWinBG = winBGTexture.getSize();

	float scaleWinBGX = static_cast<float>(windowSizeWinBG.x) / textureSizeWinBG.x;
	float scaleWinBGY = static_cast<float>(windowSizeWinBG.y) / textureSizeWinBG.y;

	// Background du menu Options
	optionsMenuBGTexture.loadFromFile("Options.png");
	optionsMenuBGSprite.setTexture(optionsMenuBGTexture);
	Vector2u windowSizeOptionsBG = window.getSize();
	Vector2u textureSizeOptionsBG = optionsMenuBGTexture.getSize();

	float scaleOptionsBGX = static_cast<float>(windowSizeOptionsBG.x) / textureSizeOptionsBG.x;
	float scaleOptionsBGY = static_cast<float>(windowSizeOptionsBG.y) / textureSizeOptionsBG.y;

	// Sprite Titre
	titleTextTexture.loadFromFile("Title.png");
	titleTextSprite.setTexture(titleTextTexture);
	titleTextSprite.setPosition(500, 150);
	Vector2u windowSizeTitleText = window.getSize();
	Vector2u textureSizeTitleText = titleTextTexture.getSize();

	float scaleTitleTextX = static_cast<float>(windowSizeTitleText.x) / textureSizeTitleText.x;
	float scaleTitleTextY = static_cast<float>(windowSizeTitleText.y) / textureSizeTitleText.y;

	// Sprite Game Over
	gameOverTextTexture.loadFromFile("GameOver.png");
	gameOverTextSprite.setTexture(gameOverTextTexture);
	Vector2u windowSizeGameOverText = window.getSize();
	Vector2u textureSizeGameOverText = gameOverBGTexture.getSize();

	float scaleGameOverTextX = static_cast<float>(windowSizeGameOverText.x) / textureSizeGameOverText.x;
	float scaleGameOverTextY = static_cast<float>(windowSizeGameOverText.y) / textureSizeGameOverText.y;

	// Sprite Win
	winTextTexture.loadFromFile("Win.png");
	winTextSprite.setTexture(winTextTexture);
	Vector2u windowSizeWinText = window.getSize();
	Vector2u textureSizeWinText = winTextTexture.getSize();

	float scaleWinTextX = static_cast<float>(windowSizeWinText.x) / textureSizeWinText.x;
	float scaleWinTextY = static_cast<float>(windowSizeWinText.y) / textureSizeWinText.y;

	// Sprite Volume
	volumeTextTexture.loadFromFile("VolumeText.png");
	volumeTextSprite.setTexture(volumeTextTexture);
	volumeTextSprite.setPosition(480, 260);
	volumeTextSprite.setScale(0.37f, 0.37f);
	Vector2u windowSizeVolumeText = window.getSize();
	Vector2u textureSizeVolumeText = volumeTextTexture.getSize();

	float scaleVolumeTextX = static_cast<float>(windowSizeVolumeText.x) / textureSizeVolumeText.x;
	float scaleVolumeTextY = static_cast<float>(windowSizeVolumeText.y) / textureSizeVolumeText.y;

	// Initialisation de la barre de volume
	volumeBarTexture.loadFromFile("VolumeBar.png");
	volumeBarSprite.setTexture(volumeBarTexture);
	volumeBarSprite.setPosition(890, 300);
	volumeBarSprite.setScale(8.0f, 8.0f);

	// Initialisation du curseur de volume
	volumeCursorTexture.loadFromFile("VolumeCursor.png");
	volumeCursorSprite.setTexture(volumeCursorTexture);
	volumeCursorSprite.setScale(8.0f, 8.0f);
	updateVolumeCursorPosition();

	// Sprite Buttons
	buttonPlayTexture.loadFromFile("PlayButton.png");
	buttonExitTexture.loadFromFile("ExitButton.png");
	buttonOptionsTexture.loadFromFile("OptionsButton.png");
	buttonResumeTexture.loadFromFile("ResumeButton.png");
	buttonReturnTexture.loadFromFile("ReturnButton.png");

	buttons.push_back(Button(buttonPlayTexture, Vector2f(500, 750)));
	buttons.push_back(Button(buttonExitTexture, Vector2f(850, 750)));
	buttons.push_back(Button(buttonResumeTexture, Vector2f(850, 200)));
	buttons.push_back(Button(buttonOptionsTexture, Vector2f(850, 475)));
	buttons.push_back(Button(buttonReturnTexture, Vector2f(50, 50)));
	buttons.push_back(Button(buttonOptionsTexture, Vector2f(1200, 750)));

	for (auto& button : buttons)
	{
		button.setScale(3.0f, 3.0f);
	}

	// Musique
	if (!levelOneMusic.openFromFile("Willderness.ogg"))
	{
		cout << "Erreur lors du chargement de la musique du menu" << endl;
	}
	else
	{
		if (levelOneMusic.getStatus() != Music::Playing)
		{
			levelOneMusic.play();
		}
	}
}

void Menu::handleVolumeControl(const RenderWindow& window, Event event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			if (volumeCursorSprite.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
			{
				isDraggingCursor = true;
			}
		}
	}
	else if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			isDraggingCursor = false;
		}
	}
	else if (event.type == Event::MouseMoved)
	{
		if (isDraggingCursor)
		{
			Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
			float newCursorX = std::max(volumeBarSprite.getPosition().x, std::min(mousePos.x, volumeBarSprite.getPosition().x + volumeBarSprite.getGlobalBounds().width - volumeCursorSprite.getGlobalBounds().width));
			float cursorY = volumeBarSprite.getPosition().y + (volumeBarSprite.getGlobalBounds().height / 2) - (volumeCursorSprite.getGlobalBounds().height / 2);
			volumeCursorSprite.setPosition(newCursorX, cursorY);

			float barWidth = volumeBarSprite.getGlobalBounds().width - volumeCursorSprite.getGlobalBounds().width;
			float cursorPos = volumeCursorSprite.getPosition().x - volumeBarSprite.getPosition().x;
			volumeLevel = (cursorPos / barWidth) * 100.0f;
			levelOneMusic.setVolume(volumeLevel); // mettre le reste en dessous
		}
	}
}

void Menu::updateVolumeCursorPosition()
{
    float barWidth = volumeBarSprite.getGlobalBounds().width - volumeCursorSprite.getGlobalBounds().width;
    float cursorX = volumeBarSprite.getPosition().x + (volumeLevel / 100.0f) * barWidth;
    float cursorY = volumeBarSprite.getPosition().y + (volumeBarSprite.getGlobalBounds().height / 2) - (volumeCursorSprite.getGlobalBounds().height / 2);
    volumeCursorSprite.setPosition(cursorX, cursorY);
}

void Menu::draw(RenderWindow& window)
{
	for (auto& button : buttons)
	{
		button.draw(window);
	}
}

int Menu::handleInput(const RenderWindow& window, Event event)
{
	for (size_t i = 0; i < buttons.size(); i++)
	{
		if (buttons[i].isClicked(window, event))
		{
			return static_cast<int>(i);
		}
	}
	return -1;
}

void Menu::menuDisplay(RenderWindow& window, int type)
{
	bool menu = true;
	bool pause = true;
	bool gameOver = true;
	bool win = true;
	bool options = true;
	int previousType = -1;
	Event event;

	while (type < 5)
	{
		if (type == 0)
		{
			levelOneMusic.pause();
			while (menu)
			{
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
						menu = false;
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						menu = false;
					}
					if (buttons[5].isClicked(window, event))
					{
						previousType = type;
						type = 4;
						options = true;
						menu = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							window.close();
							menu = false;
						}
					}

					else if (buttons[0].isClicked(window, event))
					{
						type = 5;
						menu = false;
					}
				}
				window.clear();
				window.draw(mainMenuBGSprite);
				window.draw(titleTextSprite);
				buttons[0].draw(window);
				buttons[1].draw(window);
				buttons[5].draw(window);
				window.display();
			}
		}
		if (type == 1)
		{
			levelOneMusic.pause();
			while (pause)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[2].isClicked(window, event))
					{
						pause = false;
						type = 5;
					}
					if (buttons[3].isClicked(window, event))
					{
						previousType = type;
						type = 4;
						options = true;
						pause = false;
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						pause = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							pause = false;
							type = 5;
						}
					}
				}
				window.clear();
				window.draw(pauseMenuBGSprite);
				buttons[1].draw(window);
				buttons[2].draw(window);
				buttons[3].draw(window);
				window.display();
			}
			levelOneMusic.play();
		}
		if (type == 2)
		{
			while (gameOver)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						gameOver = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							window.close();
							gameOver = false;
						}
					}
				}
				window.clear();
				window.draw(gameOverBGSprite);
				window.draw(gameOverTextSprite);
				buttons[1].draw(window);
				window.display();
			}
		}
		if (type == 3)
		{
			while (win)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[1].isClicked(window, event))
					{
						window.close();
						win = false;
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							window.close();
							win = false;
						}
					}
				}
				window.clear();
				window.draw(winBGSprite);
				window.draw(winTextSprite);
				buttons[1].draw(window);
				window.display();
			}
		}
		if (type == 4)
		{
			levelOneMusic.pause();
			while (options)
			{
				window.setView(window.getDefaultView());

				while (window.pollEvent(event))
				{
					handleVolumeControl(window, event);
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (buttons[4].isClicked(window, event))
					{
						if (previousType == 0)
						{
							type = 0;
							menu = true;
							options = false;
						}
						else if (previousType == 1)
						{
							type = 1;
							pause = true;
							options = false;
						}
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Escape)
						{
							if (previousType == 0)
							{
								type = 0;
								menu = true;
								options = false;
							}
							else if (previousType == 1)
							{
								type = 1;
								pause = true;
								options = false;
							}
						}
					}
				}
				window.clear();
				window.draw(optionsMenuBGSprite);
				buttons[4].draw(window);
				window.draw(volumeBarSprite);
				window.draw(volumeCursorSprite);
				window.draw(volumeTextSprite);
				window.display();
			}
		}
	}
	if (type == 5)
	{
		if (levelOneMusic.getStatus() != Music::Playing)
		{
			levelOneMusic.play();
		}
	}
}

		