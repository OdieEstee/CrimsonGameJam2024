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

	//Velocity constant
	int velocityCons = 2;
	Vector2f velocity;

	//Offset from gun
	float offset = 50.0f;

	//Scale constants
	float xScale = .5f;
	float yScale = .5f;

public:
	Bullet(Vector2f pos, RenderWindow &window)
	{
		sf::Vector2u textureSize = texture.getSize();
		sprite.setOrigin(((sprite.getLocalBounds().width) - 10) / 2, (sprite.getLocalBounds().height / 2) + 10);

		texture.loadFromFile("Textures/PistolBullet.png");
		
		sprite.setTexture(texture);
		
		Vector2i mousePos = Mouse::getPosition(window);

		if (mousePos.x < pos.x)
		{
			sprite.setScale(xScale, -yScale);
		}
		else
		{
			sprite.setScale(xScale, yScale);
		}
		
		float deltaX = mousePos.x - pos.x;
		float deltaY = mousePos.y - pos.y;
		float alpha = atan2(deltaY, deltaX);

		sprite.setRotation(alpha * 180 / PI);

		Vector2f direction = Vector2f(mousePos.x - pos.x, mousePos.y - pos.y);
		float length = sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length != 0) {
			direction /= length;  // Normalize the direction
		}

		velocity.x = direction.x * velocityCons;
		velocity.y = direction.y * velocityCons;

		Vector2f position;
		position.x = pos.x + direction.x * offset;
		position.y = pos.y + direction.y * offset;
		sprite.setPosition(position);
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