// Include important C++ libraries here
#include "stdafx.h"
#include <sstream>
//this adds the graphics library 
#include <SFML/Graphics.hpp>

// Make code easier to type with "using namespace"
using namespace sf;

int main()
{
	// Create a video mode object
	VideoMode vm(1980, 1200);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	// Create a texture to hold a graphic on the GPU
	Texture textureBackground;

	// Load a graphic into the texture
	textureBackground.loadFromFile("graphics/background.png");

	// Create a sprite
	Sprite spriteBackground;

	// Attach the texture to the sprite
	spriteBackground.setTexture(textureBackground);

	// Set the spriteBackground to cover the screen
	spriteBackground.setPosition(0, 0);

	// make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);


	// making the bee spite
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	// is the bee currently moving?
	bool beeActive = false;
	// how fast can the bee fly
	float beeSpeed = 0.0f;

	//making 3 cloud sprotes form 1 texture
	Texture textureCloud;
	//load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
	//3 new sprites
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	//postition clouds off screen
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);
	//are the clouds active
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	//variables to control time itself
	Clock clock;

	// track wether the game is running
	bool paused = true;

	//Draw some text
	int score = 0;
	sf::Text messageText;
	sf::Text scoreText;

	// we need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.tff");

	// set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);

	// Assign the actual message
	messageText.setString("Press Enter to start!");
	scoreText.setString("Score = 0");

	// Make it reall big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);

	// choose the colour
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	
	//Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);
	
	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		//start the game
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/

		if (!paused)
		{

			//measure time
			Time dt = clock.restart();

			//setup the bee
			if (!beeActive)
			{
				//how fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				// how high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 5;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else
			{
				//move the bee
				spriteBee.setPosition(spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds())
					, spriteBee.getPosition().y);

				//has the reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					//set it up reasy to be a while new cloud next frame
					beeActive = false;
				}
			}

			//manga the clouds
			//Cloud 1
			if (!cloud1Active)
			{
				// how fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);

				//how high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			}
			else
			{
				//move the bee
				spriteCloud1.setPosition(spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds())
					, spriteCloud1.getPosition().y);

				//has the reached the right hand edge of the screen?
				if (spriteCloud1.getPosition().x > 1920)
				{
					//set it up reasy to be a while new cloud next frame
					cloud1Active = false;
				}
			}

			//manga the clouds
			//Cloud 2
			if (!cloud2Active)
			{
				// how fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);

				//how high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			}
			else
			{
				//move the bee
				spriteCloud2.setPosition(spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds())
					, spriteCloud2.getPosition().y);

				//has the reached the right hand edge of the screen?
				if (spriteCloud2.getPosition().x > 1920)
				{
					//set it up reasy to be a while new cloud next frame
					cloud2Active = false;
				}
			}

			//manga the clouds
			//Cloud 3
			if (!cloud3Active)
			{
				// how fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);

				//how high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			}
			else
			{
				//move the bee
				spriteCloud3.setPosition(spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds())
					, spriteCloud3.getPosition().y);

				//has the reached the right hand edge of the screen?
				if (spriteCloud3.getPosition().x > 1920)
				{
					//set it up reasy to be a while new cloud next frame
					cloud3Active = false;
				}
			}

			// Update the score text
			std::stringstream ss; 
			ss << "Score = " << score;
			scoreText.setString(ss.str());


		} // end if (!paused)

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		// Clear everything from the last frame
		window.clear();
		/*
		Everything is drawn back to the front.. meaning the background first
		then what every in the background, then the middle and then the foreground
		*/
		// Draw our game scene here
		window.draw(spriteBackground);

		//draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		//draw the tree
		window.draw(spriteTree);

		//draw the bee
		window.draw(spriteBee);

		// Draw the score
		window.draw(scoreText);
		if (paused)
		{
			//draw out message
			window.draw(messageText);
		}

		// Show everything we just drew
		window.display();


	}

	return 0;
}


