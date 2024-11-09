#include "Player.cpp"

class Game {
private:

public:
	void run() {
		Player player(.5, .5);
		player.setTexture("Textures/R.png");
		RenderWindow window(VideoMode(1920, 1080), "Cultist");
		window.setFramerateLimit(60);

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{

				if (event.type == Event::Closed)
					window.close();

				if (event.type == Event::KeyPressed)
					player.processEvents(event.key.code, true);

				if (event.type == Event::KeyReleased)
					player.processEvents(event.key.code, false);
			}
			player.update();
			window.clear();
			player.draw(window);
			window.display();
		}
	}
};