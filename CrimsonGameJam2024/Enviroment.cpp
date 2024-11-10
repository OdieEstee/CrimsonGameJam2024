#include "Bullet.cpp"

class Enviroment {
private:
	Texture texture;
	Sprite sprite;
public:
	Enviroment(String filePath)
	{
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);

		sprite.setPosition(0, 0);
		sprite.setScale(3, 3);
	}

	void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	void setPosition(float x, float y)
	{
		sprite.setPosition(x, y);
	}

	void setScale(float x, float y)
	{
		sprite.setScale(x, y);
	}

	void setTexture(string filePath)
	{
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
	}
};
