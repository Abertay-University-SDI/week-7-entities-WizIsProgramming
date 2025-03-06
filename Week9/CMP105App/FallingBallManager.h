#pragma once
#include "Ball.h"
#include "math.h"
#include <vector>
class FallingBallManager
{
public:
	FallingBallManager();
	void spawn();
	void update(float dt);
	void deathCheck();
	void setWindowPtr(sf::RenderWindow* window);
	void render();
	void createBall();
	int getNumberOfBalls();
	void setTextPtr(sf::Text* textPointer);
	void updateText();
private:
	sf::RenderWindow* window;
	std::vector<Ball> balls;
	sf::Texture texture;
	int numberOfBalls;

	sf::Text* textPtr;
	sf::Font font;
	int numberOfRenderedBalls;
};

