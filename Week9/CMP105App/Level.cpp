#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//Seed random
	srand(time(0));
	//myManager.setWindowPtr(window);
	//myManager.setTextPtr(&noOfBallsText);
	//myManager.setSpawnPoint();
	myPlayer.setWindow(window);
	myPlayer.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (window->isOpen() && input->isPressed(sf::Keyboard::Escape))
	{
		window->close();
	}

	//if (input->isPressed(sf::Keyboard::Space))
	//{
	//	myManager.createBall();
	//}

	myPlayer.handleInput();
}

// Update game objects
void Level::update(float dt)
{
	myPlayer.update(dt);
	//myManager.update(dt);
	//myManager.spawn();
	//myManager.updateText();
}

// Render level
void Level::render()
{
	beginDraw();
	//myManager.render();
	window->draw(myPlayer);
	endDraw();
}
