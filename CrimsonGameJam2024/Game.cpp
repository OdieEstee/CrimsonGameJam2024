#pragma once
#include "Weapon.cpp"

class Game {
private:

public:

	//Main run function
	void run() {
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

				firstScene(window);
			}
		}
	}

	void firstScene(RenderWindow& window)
	{
		//Initialize Player
		Player player;
		player.setVelocity(3.0f);
		player.setBounds(230, 53, 875, 875);
		player.setPosition(960, 1027);

		//Initialize Animation Clock
		Clock animationClock;

		//Initialize Weapon
		Weapon weapon;

		//Initialize Bullet Clock
		Clock bulletClock;

		//Enviroment
		Enviroment ground1("Textures/Scene1/Ground1.png");

		Enviroment priest("Textures/Priest/UpIdle.png");
		priest.setPosition(1025, 125);
		priest.setScale(5.0f, 5.0f);

		Enviroment interact("Textures/Scene1/E.png");
		interact.setPosition(910, 100);
		interact.setScale(1.0f, 1.0f);

		vector<String> dialogueScreens;
		dialogueScreens.push_back("Textures/Scene1/Dialogue/2.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/3.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/4.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/5.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/6.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/7.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/8.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/9.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/10.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/11.png");
		dialogueScreens.push_back("Textures/Scene1/Dialogue/12.png");

		Enviroment dialogue("Textures/Scene1/Dialogue/1.png");
		dialogue.setPosition(0, 0);
		dialogue.setScale(1.0f, 1.0f);

		vector<Enviroment> followerVector;
		for (int j = 0; j < 13; j++) {
			for (int i = 0; i < 5; i++)
			{
				Enviroment follower("Textures/Follower/UpIdle.png");
				follower.setScale(5.0f, 5.0f);
				follower.setPosition(370 + (i * 90), 400 + (j * 40));
				followerVector.push_back(follower);
			}
		}

		for (int j = 0; j < 13; j++) {
			for (int i = 0; i < 5; i++)
			{
				Enviroment follower("Textures/Follower/UpIdle.png");
				follower.setScale(5.0f, 5.0f);
				follower.setPosition(1045 + (i * 90), 400 + (j * 40));
				followerVector.push_back(follower);
			}
		}
		

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

				if (event.type == Event::KeyPressed && event.key.code == Keyboard::E && player.getPosition().y <= 300)
				{
					window.clear();
					ground1.draw(window);
					priest.setTexture("Textures/Priest/LeftIdle.png");
					priest.draw(window);
					player.draw(window);

					//Dialogue sequence
					for (int i = 0; i < 12; i++)
					{
						window.clear();
						bool keyPress = true;
						bool wait = true;

						ground1.draw(window);
						priest.draw(window);
						player.draw(window);
						dialogue.draw(window);
						window.display();
						while (wait)
						{
							while (window.pollEvent(event))
							{
								//Close application
								if (event.type == Event::Closed)
									window.close();

								if (event.type == Event::KeyReleased)
								{
									keyPress = false;
								}
								if (event.type == Event::KeyPressed && !keyPress)
								{
									wait = false;
								}
							}
						}
						dialogue.setTexture(dialogueScreens[i]);
						
					}
					//End of dialogue
				}
			}


			Color color(146, 146, 146);
			window.clear(color);

			ground1.draw(window);
			priest.draw(window);

			if (player.getPosition().y <= 300)
			{
				interact.draw(window);
			}

			for (Enviroment it : followerVector)
			{
				it.draw(window);
			}

			
			
			//Update
			if (!player.getCombatStance())
			{
				player.update(animationClock);
				if (animationClock.getElapsedTime().asMilliseconds() >= 500)
				{
					animationClock.restart();
				}
				player.draw(window);
			}
			window.display();
		}
	}
};