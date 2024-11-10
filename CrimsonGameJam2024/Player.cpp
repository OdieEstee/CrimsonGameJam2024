#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class Player {
private:
	Sprite sprite;

	Texture UpIdleTexture;
	Texture UpWalk1Texture;
	Texture UpWalk2Texture;

	Texture DownIdleTexture;
	Texture DownWalk1Texture;
	Texture DownWalk2Texture;

	Texture LeftIdleTexture;
	Texture LeftWalk1Texture;
	Texture LeftWalk2Texture;

	Texture RightIdleTexture;
	Texture RightWalk1Texture;
	Texture RightWalk2Texture;
	
	Texture CSUpIdleTexture;
	Texture CSUpWalk1Texture;
	Texture CSUpWalk2Texture;

	Texture CSDownIdleTexture;
	Texture CSDownWalk1Texture;
	Texture CSDownWalk2Texture;

	Texture CSLeftIdleTexture;
	Texture CSLeftWalk1Texture;
	Texture CSLeftWalk2Texture;

	Texture CSRightIdleTexture;
	Texture CSRightWalk1Texture;
	Texture CSRightWalk2Texture;

	//Booleans for pressed key
	bool up;
	bool down;
	bool left;
	bool right;

	//Booleans for most recent pressed key
	bool recentUp;
	bool recentDown;
	bool recentLeft;
	bool recentRight;

	//Velocity constants
	float xVelocity = 10.0f;
	float yVelocity = 10.0f;

	//Animation Clock constant
	int animationClockMil = 500;

	//Global bounds offset constants
	int upBoundOffset = 50;
	int downBoundOffset = 53;
	int leftBoundOffset = 37;
	int rightBoundOffset = 44;

	//Combat stance boolean
	bool combatStance;

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

		//Initialize booleans for most recent pressed key
		recentUp = false;
		recentDown = false;
		recentLeft = false;
		recentRight = false;

		combatStance = false;

		//Load textures and set initial texture
		loadTextures();
		sprite.setTexture(DownIdleTexture);

		sprite.setOrigin((sprite.getLocalBounds().width) / 2, (sprite.getLocalBounds().height / 2) - 2);

		sprite.setPosition(500, 500);
	}

	bool getCombatStance()
	{
		return combatStance;
	}

	void setCombatStance(bool set)
	{
		if (combatStance == set)
		{
			return;
		}
		else
		{
			if (sprite.getTexture() == &UpIdleTexture)
			{
				sprite.setTexture(CSUpIdleTexture);
			}
			else if (sprite.getTexture() == &DownIdleTexture)
			{
				sprite.setTexture(CSDownIdleTexture);
			}
			else if (sprite.getTexture() == &LeftIdleTexture)
			{
				sprite.setTexture(CSLeftIdleTexture);
			}
			else if (sprite.getTexture() == &RightIdleTexture)
			{
				sprite.setTexture(CSRightIdleTexture);
			}
			else if (sprite.getTexture() == &UpWalk1Texture || sprite.getTexture() == &UpWalk2Texture)
			{
				sprite.setTexture(CSUpWalk1Texture);
			}
			else if (sprite.getTexture() == &DownWalk1Texture || sprite.getTexture() == &DownWalk2Texture)
			{
				sprite.setTexture(CSDownWalk1Texture);
			}
			else if (sprite.getTexture() == &LeftWalk1Texture || sprite.getTexture() == &LeftWalk2Texture)
			{
				sprite.setTexture(CSLeftWalk1Texture);
			}
			else if (sprite.getTexture() == &RightWalk1Texture || sprite.getTexture() == &RightWalk2Texture)
			{
				sprite.setTexture(CSRightWalk1Texture);
			}

			else if (sprite.getTexture() == &CSUpIdleTexture)
			{
				sprite.setTexture(UpIdleTexture);
			}
			else if (sprite.getTexture() == &CSDownIdleTexture)
			{
				sprite.setTexture(DownIdleTexture);
			}
			else if (sprite.getTexture() == &CSLeftIdleTexture)
			{
				sprite.setTexture(LeftIdleTexture);
			}
			else if (sprite.getTexture() == &CSRightIdleTexture)
			{
				sprite.setTexture(RightIdleTexture);
			}
			else if (sprite.getTexture() == &CSUpWalk1Texture || sprite.getTexture() == &CSUpWalk2Texture)
			{
				sprite.setTexture(UpWalk1Texture);
			}
			else if (sprite.getTexture() == &CSDownWalk1Texture || sprite.getTexture() == &CSDownWalk2Texture)
			{
				sprite.setTexture(DownWalk1Texture);
			}
			else if (sprite.getTexture() == &CSLeftWalk1Texture || sprite.getTexture() == &CSLeftWalk2Texture)
			{
				sprite.setTexture(LeftWalk1Texture);
			}
			else if (sprite.getTexture() == &CSRightWalk1Texture || sprite.getTexture() == &CSRightWalk2Texture)
			{
				sprite.setTexture(RightWalk1Texture);
			}
			if (set)
			{
				combatStance = true;
			}
			else
			{
				combatStance = false;
			}
		}
	}

	//Draw sprite to a window
	void draw(RenderWindow& window) 
	{
		window.draw(sprite);
	}

	//Load textures
	void loadTextures()
	{
		UpIdleTexture.loadFromFile("Textures/UpIdle.png");
		UpWalk1Texture.loadFromFile("Textures/UpWalk1.png");
		UpWalk2Texture.loadFromFile("Textures/UpWalk2.png");

		DownIdleTexture.loadFromFile("Textures/DownIdle.png");
		DownWalk1Texture.loadFromFile("Textures/DownWalk1.png");
		DownWalk2Texture.loadFromFile("Textures/DownWalk2.png");

		LeftIdleTexture.loadFromFile("Textures/LeftIdle.png");
		LeftWalk1Texture.loadFromFile("Textures/LeftWalk1.png");
		LeftWalk2Texture.loadFromFile("Textures/LeftWalk2.png");

		RightIdleTexture.loadFromFile("Textures/RightIdle.png");
		RightWalk1Texture.loadFromFile("Textures/RightWalk1.png");
		RightWalk2Texture.loadFromFile("Textures/RightWalk2.png");

		CSUpIdleTexture.loadFromFile("Textures/Combat Stance/CSUpIdle.png");
		CSUpWalk1Texture.loadFromFile("Textures/Combat Stance/CSUpWalk1.png");
		CSUpWalk2Texture.loadFromFile("Textures/Combat Stance/CSUpWalk2.png");

		CSDownIdleTexture.loadFromFile("Textures/Combat Stance/CSDownIdle.png");
		CSDownWalk1Texture.loadFromFile("Textures/Combat Stance/CSDownWalk1.png");
		CSDownWalk2Texture.loadFromFile("Textures/Combat Stance/CSDownWalk2.png");

		CSLeftIdleTexture.loadFromFile("Textures/Combat Stance/CSLeftIdle.png");
		CSLeftWalk1Texture.loadFromFile("Textures/Combat Stance/CSLeftWalk1.png");
		CSLeftWalk2Texture.loadFromFile("Textures/Combat Stance/CSLeftWalk2.png");

		CSRightIdleTexture.loadFromFile("Textures/Combat Stance/CSRightIdle.png");
		CSRightWalk1Texture.loadFromFile("Textures/Combat Stance/CSRightWalk1.png");
		CSRightWalk2Texture.loadFromFile("Textures/Combat Stance/CSRightWalk2.png");
	}

	//Process keyboard inputs
	void processEvents(Keyboard::Key key, bool checkPressed) 
	{
		//Set specific boolean to true based off of keyboard input
		if (checkPressed) {
			if (key == Keyboard::W) 
			{
				//Check if most recent key press
				if (!up)
				{
					recentUp = true;
					recentDown = recentLeft = recentRight = false;
				}
				up = true;
			}

			if (key == Keyboard::S)
			{ 
				//Check if most recent key press
				if (!down)
				{
					recentDown = true;
					recentUp = recentLeft = recentRight = false;
				}
				down = true;
			}

			if (key == Keyboard::A)
			{
				//Check if most recent key press
				if (!left)
				{
					recentLeft = true;
					recentDown = recentUp = recentRight = false;
				}
				left = true;
			}

			if (key == Keyboard::D)
			{
				//Check if most recent key press
				if (!right)
				{
					recentRight = true;
					recentDown = recentLeft = recentUp = false;
				}
				right = true;
			}

			if (key == Keyboard::Up)
			{
				//Check if most recent press
				if (!up)
				{
					recentUp = true;
					recentDown = recentLeft = recentRight = false;
				}
				up = true;
			}

			if (key == Keyboard::Down)
			{
				//Check if most recent press
				if (!down)
				{
					recentDown = true;
					recentUp = recentLeft = recentRight = false;
				}
				down = true;
			}

			if (key == Keyboard::Left)
			{
				//Check if most recent press
				if (!left)
				{
					recentLeft = true;
					recentDown = recentUp = recentRight = false;
				}
				left = true;
			}

			if (key == Keyboard::Right)
			{
				//Check if most recent press
				if (!right)
				{
					recentRight = true;
					recentDown = recentLeft = recentUp = false;
				}
				right = true;
			}
		}

		//Set specific boolean to false based off of keyboard input
		else {
			if (key == Keyboard::W)
			{
				up = recentUp = false;
			}
			if (key == Keyboard::S)
			{
				down = recentDown = false;
			}
			if (key == Keyboard::A)
			{
				left = recentLeft = false;
			}
			if (key == Keyboard::D)
			{
				right = recentRight = false;
			}
			if (key == Keyboard::Up)
			{
				up = recentUp = false;
			}
			if (key == Keyboard::Down)
			{
				down = recentDown = false;
			}
			if (key == Keyboard::Left)
			{
				left = recentLeft = false;
			}
			if (key == Keyboard::Right)
			{
				right = recentRight = false;
			}
		}
	}

	//Function to handle animation logic
	void animationHandler(Clock animationClock)
	{
		if(!combatStance)
		{ 
			if (recentUp || (up && !recentDown && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &UpWalk1Texture && sprite.getTexture() != &UpWalk2Texture)
				{
					sprite.setTexture(UpWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &UpWalk2Texture)
						{
							sprite.setTexture(UpWalk2Texture);
						}
						else
						{
							sprite.setTexture(UpWalk1Texture);
						}
					}
				}
			}
			if (recentDown || (down && !recentUp && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &DownWalk1Texture && sprite.getTexture() != &DownWalk2Texture)
				{
					sprite.setTexture(DownWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &DownWalk2Texture)
						{
							sprite.setTexture(DownWalk2Texture);
						}
						else
						{
							sprite.setTexture(DownWalk1Texture);
						}
					}
				}
			}
			if (recentLeft || (left && !recentUp && !recentDown && !recentRight))
			{
				if (sprite.getTexture() != &LeftWalk1Texture && sprite.getTexture() != &LeftWalk2Texture)
				{
					sprite.setTexture(LeftWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &LeftWalk2Texture)
						{
							sprite.setTexture(LeftWalk2Texture);
						}
						else
						{
							sprite.setTexture(LeftWalk1Texture);
						}
					}
				}
			}
			if (recentRight || (right && !recentUp && !recentDown && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &RightWalk1Texture && sprite.getTexture() != &RightWalk2Texture)
				{
					sprite.setTexture(RightWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &RightWalk2Texture)
						{
							sprite.setTexture(RightWalk2Texture);
						}
						else
						{
							sprite.setTexture(RightWalk1Texture);
						}
					}
				}
			}
			if (!up && !down && !left && !right)
			{
				if (sprite.getTexture() == &UpWalk1Texture || sprite.getTexture() == &UpWalk2Texture)
				{
					sprite.setTexture(UpIdleTexture);
				}
				if (sprite.getTexture() == &DownWalk1Texture || sprite.getTexture() == &DownWalk2Texture)
				{
					sprite.setTexture(DownIdleTexture);
				}
				if (sprite.getTexture() == &LeftWalk1Texture || sprite.getTexture() == &LeftWalk2Texture)
				{
					sprite.setTexture(LeftIdleTexture);
				}
				if (sprite.getTexture() == &RightWalk1Texture || sprite.getTexture() == &RightWalk2Texture)
				{
					sprite.setTexture(RightIdleTexture);
				}
			}
		}

		else
		{
			if (recentUp || (up && !recentDown && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &CSUpWalk1Texture && sprite.getTexture() != &CSUpWalk2Texture)
				{
					sprite.setTexture(CSUpWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &CSUpWalk2Texture)
						{
							sprite.setTexture(CSUpWalk2Texture);
						}
						else
						{
							sprite.setTexture(CSUpWalk1Texture);
						}
					}
				}
			}
			if (recentDown || (down && !recentUp && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &CSDownWalk1Texture && sprite.getTexture() != &CSDownWalk2Texture)
				{
					sprite.setTexture(CSDownWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &CSDownWalk2Texture)
						{
							sprite.setTexture(CSDownWalk2Texture);
						}
						else
						{
							sprite.setTexture(CSDownWalk1Texture);
						}
					}
				}
			}
			if (recentLeft || (left && !recentUp && !recentDown && !recentRight))
			{
				if (sprite.getTexture() != &CSLeftWalk1Texture && sprite.getTexture() != &CSLeftWalk2Texture)
				{
					sprite.setTexture(CSLeftWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &CSLeftWalk2Texture)
						{
							sprite.setTexture(CSLeftWalk2Texture);
						}
						else
						{
							sprite.setTexture(CSLeftWalk1Texture);
						}
					}
				}
			}
			if (recentRight || (right && !recentUp && !recentDown && !recentLeft && !recentRight))
			{
				if (sprite.getTexture() != &CSRightWalk1Texture && sprite.getTexture() != &CSRightWalk2Texture)
				{
					sprite.setTexture(CSRightWalk1Texture);
				}
				else
				{
					if (animationClock.getElapsedTime().asMilliseconds() >= animationClockMil)
					{
						if (sprite.getTexture() != &CSRightWalk2Texture)
						{
							sprite.setTexture(CSRightWalk2Texture);
						}
						else
						{
							sprite.setTexture(CSRightWalk1Texture);
						}
					}
				}
			}
			if (!up && !down && !left && !right)
			{
				if (sprite.getTexture() == &CSUpWalk1Texture || sprite.getTexture() == &CSUpWalk2Texture)
				{
					sprite.setTexture(CSUpIdleTexture);
				}
				if (sprite.getTexture() == &CSDownWalk1Texture || sprite.getTexture() == &CSDownWalk2Texture)
				{
					sprite.setTexture(CSDownIdleTexture);
				}
				if (sprite.getTexture() == &CSLeftWalk1Texture || sprite.getTexture() == &CSLeftWalk2Texture)
				{
					sprite.setTexture(CSLeftIdleTexture);
				}
				if (sprite.getTexture() == &CSRightWalk1Texture || sprite.getTexture() == &CSRightWalk2Texture)
				{
					sprite.setTexture(CSRightIdleTexture);
				}
			}
		}
	}

	//Bounds handler
	void boundsHandler(Vector2f* movement)
	{
		if (sprite.getPosition().x + movement->x < (0 + leftBoundOffset))
		{
			if (sprite.getPosition().x != 0 + leftBoundOffset)
			{
				movement->x = -(sprite.getPosition().x) + leftBoundOffset;
			}
			else
			{
				movement->x = 0;
			}
		}
		if (sprite.getPosition().x + movement->x > (1920 - rightBoundOffset))
		{
			if (sprite.getPosition().x != 1920 - rightBoundOffset)
			{
				movement->x = (1920 - rightBoundOffset) - sprite.getPosition().x;
			}
			else
			{
				movement->x = 0;
			}
		}
		if (sprite.getPosition().y + movement->y < (0 + upBoundOffset))
		{
			if (sprite.getPosition().y != 0 + upBoundOffset)
			{
				movement->y = -(sprite.getPosition().y) + upBoundOffset;
			}
			else
			{
				movement->y = 0;
			}
		}
		if (sprite.getPosition().y + movement->y > (1080 - downBoundOffset))
		{
			if (sprite.getPosition().y != 1080 - downBoundOffset)
			{
				movement->y = (1080 - downBoundOffset) - sprite.getPosition().y;
			}
			else
			{
				movement->y = 0;
			}
		}
	}

	//Update function for every frame (60 times a second)
	void update(Clock animationClock)
	{
		//Adjust movement vector based off of keyboard input
		Vector2f movement;
		if (up)
		{
			movement.y -= 1.0f;
		}

		if (down) 
		{
			movement.y += 1.0f;
		}
		if (left)
		{
			movement.x -= 1.0f;
		}
		if (right)
		{
			movement.x += 1.0f;
		}

		if (movement.x != 0.0f || movement.y != 0.0f)
		{
			float length = sqrt(movement.x * movement.x + movement.y * movement.y);
			movement.x /= length;
			movement.y /= length;

			// Reapply consistent speed
			float consistentSpeed = min(xVelocity, yVelocity);
			movement.x *= consistentSpeed;
			movement.y *= consistentSpeed;
		}

		boundsHandler(&movement);
		animationHandler(animationClock);

		//Move sprite
		sprite.move(movement);
	}

	Vector2f getPosition()
	{
		return sprite.getPosition();
	}
};