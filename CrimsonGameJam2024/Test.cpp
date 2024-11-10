#include "Game.cpp"

class Test {
public:
	bool spawnPlayerBool = false;
	bool spawnWeaponBool = false;

	void spawnPlayer()
	{
		spawnPlayerBool = true;
	}

	void spawnWeapon()
	{
		spawnWeaponBool = true;
	}

	void run()
	{
		//Initialize Player
		Player player(5.0f, 5.0f);
		//Initialize Animation Clock
		Clock animationClock;

		//Initialize Weapon
		Weapon weapon(5.0f, 5.0f);

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
				if (spawnPlayerBool)
				{
					if (event.type == Event::KeyPressed)
						player.processEvents(event.key.code, true);

					if (event.type == Event::KeyReleased)
						player.processEvents(event.key.code, false);
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Num1)
						{
							if (!player.getCombatStance())
							{
								player.setCombatStance(true);
							}
							else
							{
								player.setCombatStance(false);
							}
						}
					}
				}
				
			}

			Color color(146, 146, 146);
			window.clear(color);
			//Update
			if (spawnPlayerBool)
			{
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
					animationClock.restart();
				player.draw(window);
			}

			if (spawnWeaponBool && player.getCombatStance())
			{
				weapon.update(player, window);
				weapon.draw(window);
			}
			window.display();
		}
	}
};