#include "Game.cpp"

class Test {
public:
	bool spawnPlayerBool = false;
	bool spawnWeaponBool = false;
	bool spacebarPressed = false;

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
		Player player;
		//Initialize Animation Clock
		Clock animationClock;

		//Initialize Weapon
		Weapon weapon;

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
					if (spawnWeaponBool && player.getCombatStance()) {
						if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) 
						{
							if (!spacebarPressed)
							{
								if (weapon.getState())
								{
									if (bulletClock.getElapsedTime().asMilliseconds() >= 100)
									{
										weapon.shoot(window); // Fire the weapon
										bulletClock.restart(); // Restart the cooldown clock
										spacebarPressed = true;
									}
								}
								else
								{
									spacebarPressed = true;
								}
							}
						}

						if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space) 
						{
							// Spacebar released
							spacebarPressed = false;

						}
						if (spacebarPressed && !weapon.getState())
						{
							if (bulletClock.getElapsedTime().asMilliseconds() >= 100) 
							{
								weapon.shoot(window); // Fire the weapon
								bulletClock.restart(); // Restart the cooldown clock
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
				
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
					animationClock.restart();
				player.draw(window);
			}
			else if (spawnWeaponBool && player.getCombatStance() && !player.isUpTexture())
			{
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
					animationClock.restart();
				player.draw(window);

				weapon.update(player, window);
				weapon.draw(window);
				for (Bullet& bullet : weapon.getBullets())
				{
					bullet.draw(window);
				}
			}
			else if (spawnPlayerBool && !player.getCombatStance())
			{
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
					animationClock.restart();
				player.draw(window);
			}

			window.display();
		}
	}
};