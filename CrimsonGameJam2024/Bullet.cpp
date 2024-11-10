#pragma once

#include "SFML/Graphics.hpp"
#include <string>

#define PI 3.14159265358979323846

using namespace std;
using namespace sf;

class Bullet {
private:
	Sprite sprite;
	Texture texture;
	Vector2f velocity;
public:
	Bullet(Vector2f pos, RenderWindow &window)
	{
		sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);

		sprite.setScale(5.0f, 5.0f);

		texture.loadFromFile("Textures/PistolBullet.png");
		sprite.setTexture(texture);
		sprite.setPosition(pos);
		
		Vector2i mousePos = Mouse::getPosition(window);

		float deltaX = mousePos.x - pos.x;
		float deltaY = mousePos.y - pos.y;
		float alpha = atan2(deltaY, deltaX);

		sprite.setRotation(alpha * 180 / PI);

		Vector2f direction = Vector2f(mousePos.x - pos.x, mousePos.y - pos.y);
		float length = sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length != 0) {
			direction /= length;  // Normalize the direction
		}

		velocity.x = direction.x * 2;
		velocity.y = direction.y * 2;
	}

	Vector2f getPosition()
	{
		return sprite.getPosition();
	}

	void update()
	{
		sprite.move(velocity);
	}

	void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	bool isOutOfBounds() 
	{
		return sprite.getPosition().x < 0 || sprite.getPosition().x > 1920 || sprite.getPosition().y < 0 || sprite.getPosition().y > 1080;
	}
};