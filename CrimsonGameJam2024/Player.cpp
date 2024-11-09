#pragma once
#include "Bullet.cpp"

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
	int xVelocity = 5;
	int yVelocity = 5;

	//Animation Clock constant
	int animationClockMil = 500;

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

		//Load textures and set initial texture
		loadTextures();
		sprite.setTexture(DownIdleTexture);
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

	//Update function for every frame (60 times a second)
	void update(Clock animationClock)
	{
		//Adjust movement vector based off of keyboard input
		Vector2f movement;
		if (up)
		{
			movement.y -= 1.0f * yVelocity;
		}

		if (down) 
		{
			movement.y += 1.0f * yVelocity;
		}
		if (left)
		{
			movement.x -= 1.0f * xVelocity;
		}
		if (right)
		{
			movement.x += 1.0f * xVelocity;
		}

		animationHandler(animationClock);

		//Move sprite
		sprite.move(movement);
	}


};