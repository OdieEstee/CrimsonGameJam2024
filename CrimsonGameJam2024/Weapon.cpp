#pragma once
#include <vector>

#include "Player.cpp"
#include "Bullet.cpp"
#define PI 3.14159265358979323846

class Weapon {
private:
	Sprite sprite;
	Texture testTexture;

	//Position from player offsets constants
	int xOffset = 150;
	int yOffset = 75;

	int xScale;
	int yScale;

	float rotationRadius = 50.0f;

	vector<Bullet> bullets;

public:
	Weapon(float x, float y)
	{
		//Set scale of sprite to <x,y>
		sprite.setScale(Vector2f(x, y));

		xScale = x;
		yScale = y;

		testTexture.loadFromFile("Textures/Pistol.png");
		sprite.setTexture(testTexture);

		sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);
	}

	void shoot(Clock bulletClock, RenderWindow &window)
	{
		if (bulletClock.getElapsedTime().asMilliseconds() >= 100)
		{
			Bullet newBullet(sprite.getPosition(), window);
			bullets.push_back(newBullet);
		}
	}

	void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	void update(Player player, RenderWindow &window)
	{
		Vector2i mousePos = Mouse::getPosition(window);
		Vector2f playerPos = player.getPosition();

		//Calculate angle between cursor and weapon sprite at horizon
		float deltaX = mousePos.x - playerPos.x;
		float deltaY = mousePos.y - playerPos.y;
		float alpha = atan2(deltaY, deltaX);

		//Calculate distance between cursor and weapon sprite
		float weaponX = playerPos.x + rotationRadius * cos(alpha);
		float weaponY = playerPos.y + rotationRadius * sin(alpha);

		if (mousePos.x < playerPos.x)
		{
			sprite.setScale(xScale, -yScale);
		}
		else
		{
			sprite.setScale(xScale, yScale);
		}

		sprite.setPosition(weaponX, weaponY);
		sprite.setRotation(alpha * 180 / PI);

		

		

		for (auto it = bullets.begin(); it != bullets.end(); ) {
			it->update();  // Update bullet position

			if (it->isOutOfBounds()) {
				// Erase the bullet if it is out of bounds
				it = bullets.erase(it);  // erase returns the next iterator
			}
			else {
				++it;  // Only increment if we don't erase
			}
		}
	}

	vector<Bullet> getBullets()
	{
		return bullets;
	}
};
