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

		//Bullet clock
		Clock bulletClock;

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
					if (spawnWeaponBool && player.getCombatStance())
					{
						if (event.type == Event::KeyPressed)
						{
							if (event.key.code == Keyboard::Space)
							{
								
								weapon.shoot(bulletClock, window);
								if (bulletClock.getElapsedTime().asMilliseconds() >= 100)
								{
									bulletClock.restart();
								}
							}
						}
					}
				}
				
			}

			Color color(146, 146, 146);
			window.clear(color);
			//Update
			if (spawnWeaponBool && player.getCombatStance() && player.isUpTexture())
			{
				weapon.update(player, window);
				weapon.draw(window);
				for (Bullet& bullet : weapon.getBullets())
				{
					bullet.draw(window);
				}
			}

			if (spawnPlayerBool)
			{
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
					animationClock.restart();
				player.draw(window);
			}

			if (spawnWeaponBool && player.getCombatStance() && !player.isUpTexture())
			{
				weapon.update(player, window);
				weapon.draw(window);
				for (Bullet& bullet : weapon.getBullets())
				{
					bullet.draw(window);
				}
			}
			window.display();
		}
	}
};