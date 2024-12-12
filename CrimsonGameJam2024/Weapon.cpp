#pragma once
#include <vector>

#include "Player.cpp"
#define PI 3.14159265358979323846

class Weapon {
private:
	Sprite sprite;
	Texture pistolTexture;
	Texture rifleTexture;

	//Position from player offsets constants
	int xOffset = 150;
	int yOffset = 75;

	//Scale constants
	float xScale = 5.0f;
	float yScale = 5.0f;

	//Radius from player
	float rotationRadius = 50.0f;

	vector<Bullet> bullets;

	//Boolean for state of weapon
	bool isPistol;

public:
	Weapon()
	{
		//Set scale of sprite to <x,y>
		sprite.setScale(Vector2f(xScale, yScale));

		pistolTexture.loadFromFile("Textures/Pistol.png");
		rifleTexture.loadFromFile("Textures/Rifle.png");
		sprite.setTexture(pistolTexture);

		sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);

		isPistol = true;

		setPistol(true);
	}

	void setPistol(bool set)
	{
		if (set == isPistol)
		{
			return;
		}
		if (!isPistol && set)
		{
			sprite.setScale(Vector2f(xScale, yScale));

			sprite.setTexture(pistolTexture);

			sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);

			isPistol = true;
		}
		if (isPistol && !set)
		{
			sprite.setScale(Vector2f(xScale, yScale));

			sprite.setTexture(rifleTexture);

			sprite.setOrigin((sprite.getLocalBounds().width) / 2 + 5, (sprite.getLocalBounds().height / 2) - 2);

			isPistol = false;
		}
	}

	bool getState()
	{
		return isPistol;
	}

	void shoot(RenderWindow &window)
	{
		Bullet newBullet(sprite.getPosition(), window);
		bullets.push_back(newBullet);
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
