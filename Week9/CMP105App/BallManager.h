#pragma once
#include "Ball.h"
#include "math.h"
#include <vector>
class BallManager
{
public:
	BallManager();
	void spawn();
	void update(float dt);
	void deathCheck();
	void setWindowPtr(sf::RenderWindow* window);
	void setSpawnPoint();
	void render();
	void createBall();
	int getNumberOfBalls();
	void setTextPtr(sf::Text* textPointer);
	void updateText();
private:
	sf::RenderWindow* window;
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	int numberOfBalls;

	sf::Text* textPtr;
	sf::Font font;
	int numberOfRenderedBalls;
};

