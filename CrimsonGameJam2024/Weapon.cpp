#pragma once

#include "Player.cpp"
#define PI 3.14159265358979323846

class Weapon {
private:
	Sprite sprite;
	Texture testTexture;

	//Position from player offsets constants
	int xOffset = 150;
	int yOffset = 75;

	float rotationRadius = 60.0f;

public:
	Weapon(float x, float y)
	{
		//Set scale of sprite to <x,y>
		sprite.setScale(Vector2f(x, y));

		testTexture.loadFromFile("Textures/TestGun.png");
		sprite.setTexture(testTexture);

		sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);
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

		sprite.setPosition(weaponX, weaponY);
		sprite.setRotation(alpha * 180 / PI);
	}
};
