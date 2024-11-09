#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace sf;

class Bullet {
private:
	Sprite sprite;
	Texture texture;

public:
	Bullet()
	{

	}

	void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	void update()
	{

	}
};