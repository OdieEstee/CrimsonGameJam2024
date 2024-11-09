#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace sf;

class Player {
private:
	Sprite sprite;
	Texture texture;
	
	//Booleans for pressed key
	bool up;
	bool down;
	bool left;
	bool right;

	//Velocity constants
	int xVelocity = 10;
	int yVelocity = 10;

public:
	//Constructor with parameters for scale (defualt = 1)
	Player(float x, float y) 
	{
		//Set scale of sprite to <x,y>
		sprite.setScale(Vector2f(x, y));

		//Initialize booleans for pressed key
		up = false;
		down = false;
		left = false;
		right = false;
	}

	//Set texture from a file path
	void setTexture(string filePath)
	{
		//Load texture from file path
		texture.loadFromFile(filePath);

		//Set sprite texture to texture
		sprite.setTexture(texture);
	}

	//Draw sprite to a window
	void draw(RenderWindow& window) {
		window.draw(sprite);
	}


	void processEvents(Keyboard::Key key, bool checkPressed) 
	{
		if (checkPressed) {
			if (key == Keyboard::W)
				up = true;
			if (key == Keyboard::S)
				down = true;
			if (key == Keyboard::A)
				left = true;
			if (key == Keyboard::D)
				right = true;
		}

		else {
			if (key == Keyboard::W)
				up = false;
			if (key == Keyboard::S)
				down = false;
			if (key == Keyboard::A)
				left = false;
			if (key == Keyboard::D)
				right = false;
		}
	}

	void update()
	{
		Vector2f movement;
		if (up)
			movement.y -= 1.0f * yVelocity;
		if (down)
			movement.y += 1.0f * yVelocity;
		if (left)
			movement.x -= 1.0f * xVelocity;
		if (right)
			movement.x += 1.0f * xVelocity;

		sprite.move(movement);
	}


};