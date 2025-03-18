#include "Player.hpp"
#include "Platform.h"
#include <cmath>


Player::Player(int health, float aspeed, int aenergy) : hp(health), speed(aspeed), energy(aenergy), jump(false), initialY(0.f), initialX(0.f), maxJumpHeight(350.f)
{
	if (!playerTexture.loadFromFile("player.png"))
	{
		cout << "Error loading player texture" << endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	playerPosition = Vector2f(500.f, 300.f);
	playerSprite.setPosition(playerPosition);
	playerSprite.setScale(1.5f, 1.5f);
	FloatRect playerBounds = playerSprite.getGlobalBounds();
	FloatRect playerLocalBounds = playerSprite.getLocalBounds();
	playerSprite.setOrigin(playerLocalBounds.width / 2, playerLocalBounds.height / 2);

	grapinTexture.loadFromFile("cable-grapin.jpg");
	
	line.setTexture(&grapinTexture);
	line.setPosition(playerPosition);
	
	FloatRect grapinBounds = line.getGlobalBounds();
	
}


void Player::draw(RenderWindow& window)
{
	window.draw(playerSprite);
	
}

void Player::update(float deltatime,std::vector<std::unique_ptr<Tiles>>& platforms, RenderWindow& window, Event event)
{

	if (watchanime.getElapsedTime().asSeconds() > 0.5f) {
		IntRect newRect = playerSprite.getTextureRect();
		newRect.left += 64;
		if (newRect.left >= 256) { newRect.left -= 256; }
		playerSprite.setTextureRect(newRect);
		watchanime.restart();
	}
    if (Keyboard::isKeyPressed(Keyboard::Space) && !jump)
    {
        float currentTime = Clock().getElapsedTime().asSeconds();

        if (1 <= jumpCooldown.getElapsedTime().asSeconds())
        {
            jump = true;
            initialY = playerSprite.getPosition().y;
			jumpCooldown.restart();
        }
    }

    if (jump)
    {
        if (playerSprite.getPosition().y > initialY - maxJumpHeight)
        {
            playerSprite.move(0,-speed * 0.5f);
        }
    	if (sf::Event::KeyReleased)
    	{
    		if (event.key.code == sf::Keyboard::Space)
    		{
    			std::cout << "endJump" << std::endl;
    			jump = false;
    		}
    	}
        else
        {
            jump = false;
        }
    }
	hasToMoveDown = true;
	for (auto& plat: platforms)
	{
		if (plat->sprite.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
		{
			
			if (plat->sprite.getPosition().y < playerSprite.getPosition().y)
			{
				hasToMoveDown = true;
			}
			else
			{
				playerSprite.setPosition(playerSprite.getPosition().x,plat->sprite.getPosition().y -95);
				hasToMoveDown = false;
			}
		}
	}
	if (hasToMoveDown)
	{
		playerSprite.move( 0,speed * deltatime * 5.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		playerSprite.move(-speed * deltatime,0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && Keyboard::isKeyPressed(Keyboard::LShift)) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerSprite.getPosition().x;
			playerSprite.move( -100,0);
			dashCooldown.restart();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerSprite.move(speed * deltatime,0);
	}

	if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
		float currentTime = Clock().getElapsedTime().asSeconds();

		if (1 <= dashCooldown.getElapsedTime().asSeconds()) {
			initialX = playerSprite.getPosition().x;
			playerSprite.move( 100,0);
			dashCooldown.restart();
		}
	}

	

}

bool rayIntersectsRect(const sf::Vector2f& rayOrigin,
	const sf::Vector2f& rayDir,
	const sf::FloatRect& rect,
	sf::Vector2f& hitPoint) {


	float tMin = 0.0f, tMax = 1000.0f; // Distance min et max pour le recast
	sf::Vector2f invDir(1.0f / rayDir.x, 1.0f / rayDir.y); // Inverse du vecteur direction

	// Limites du rectangle
	sf::Vector2f rectMin(rect.left, rect.top);
	sf::Vector2f rectMax(rect.left + rect.width, rect.top + rect.height);

	// Vérification sur X
	float t1x = (rectMin.x - rayOrigin.x) * invDir.x;
	float t2x = (rectMax.x - rayOrigin.x) * invDir.x;
	if (t1x > t2x) std::swap(t1x, t2x);

	// Vérification sur Y
	float t1y = (rectMin.y - rayOrigin.y) * invDir.y;
	float t2y = (rectMax.y - rayOrigin.y) * invDir.y;
	if (t1y > t2y) std::swap(t1y, t2y);

	tMin = std::max(tMin, t1x);
	tMax = std::min(tMax, t2x);

	tMin = std::max(tMin, t1y);
	tMax = std::min(tMax, t2y);

	if (tMax < tMin) return false; // Pas d'intersection

	hitPoint = rayOrigin + tMin * rayDir; // Calcul du point d'impact
	return true;
}

Vector2f normalize(const Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	if (length == 0.0f)
		return Vector2f(0.0f, 0.0f);
	return Vector2f(vector.x / length, vector.y / length);
}

bool presqueEgal(const sf::Vector2f& a, const sf::Vector2f& b, float epsilon = 0.0001f) {
	return (std::fabs(a.x - b.x) < epsilon) && (std::fabs(a.y - b.y) < epsilon);
}


void Player::grapin(RenderWindow& window, vector<unique_ptr<Tiles>>& currentMap, float deltatime) {
	Vector2i Mousepos = Mouse::getPosition(window);
	Vector2f rayOrigin = playerSprite.getPosition(); // Origine du rayon
	Vector2f rayDir = normalize(Vector2f(Mousepos) - rayOrigin);

	Vector2f hitPoint;
	bool hit = false;

	for (auto& plat : currentMap) {
		if (rayIntersectsRect(rayOrigin, rayDir, plat->sprite.getGlobalBounds(), hitPoint)) {
			hit = true;
			break;
		}
	}

	float distance = sqrt(pow(playerSprite.getPosition().x - hitPoint.x, 2) + pow(playerSprite.getPosition().y - hitPoint.y, 2));
	float angle = (atan2(hitPoint.y - playerSprite.getPosition().y, hitPoint.x - playerSprite.getPosition().x)) * (180.0 / 3.14f);


	
	if (Mouse::isButtonPressed(Mouse::Left) && hit) {
	

		line.setSize(Vector2f(distance, 5));
		line.setPosition(rayOrigin);
		line.setRotation(angle);
		
		while(!presqueEgal(hitPoint, playerSprite.getPosition(), 5.f))
		{
			playerSprite.move(normalize(hitPoint - playerSprite.getPosition()));
		}
		


	}
	
	window.draw(line);
	
	
	
	
	
	

}

Vector2f Player::getPosition() const {
	return playerPosition;
}



