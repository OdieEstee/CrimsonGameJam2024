#pragma once
#include "Player.cpp"

class Game {
private:

public:
	//Main run function
	void run() {
		//Initialize Player
		Player player(.5, .5);
		player.setTexture("Textures/R.png");

		//Create window
		RenderWindow window(VideoMode(1920, 1080), "Cultist");
		window.setFramerateLimit(60);

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				//Close application
				if (event.type == Event::Closed)
					window.close();

				//Take in keyboard input for movement
				if (event.type == Event::KeyPressed)
					player.processEvents(event.key.code, true);

				if (event.type == Event::KeyReleased)
					player.processEvents(event.key.code, false);
			}

			//Update
			player.update();
			window.clear();
			player.draw(window);
			window.display();
		}
	}
};