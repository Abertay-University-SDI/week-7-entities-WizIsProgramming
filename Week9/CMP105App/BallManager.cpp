#include "BallManager.h"

BallManager::BallManager()
{
	window = nullptr;
	textPtr = nullptr;
	numberOfRenderedBalls = 0;
	spawnPoint = sf::Vector2f(500.f, 250.f);
	texture.loadFromFile("gfx/Beach_Ball.png");
	numberOfBalls = 0;
	font.loadFromFile("font/arial.ttf");
}

void BallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity((rand() % 400 - 200), rand() % 400 - 200);
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
}

void BallManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > window->getSize().x)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > window->getSize().y)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void BallManager::render()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
	window->draw(*textPtr);
}

void BallManager::setSpawnPoint()
{
	spawnPoint = (sf::Vector2f(-50 + window->getSize().x / 2, -50 + window->getSize().y / 2));
}

void BallManager::setWindowPtr(sf::RenderWindow* windowPointer)
{
	window = windowPointer;
}

void BallManager::setTextPtr(sf::Text* textPointer)
{
	textPtr = textPointer;
}

void BallManager::updateText()
{
	textPtr->setFont(font);
	textPtr->setFillColor(sf::Color::Magenta);
	textPtr->setCharacterSize(20);
	textPtr->setString(std::to_string(getNumberOfBalls()));
}

void BallManager::createBall()
{
	balls.push_back(Ball());
	balls[numberOfBalls].setAlive(true);
	balls[numberOfBalls].setPosition(spawnPoint);
	balls[numberOfBalls].setTexture(&texture);
	balls[numberOfBalls].setSize(sf::Vector2f(100, 100));
	balls[numberOfBalls].setVelocity((rand() % 400 - 200), rand() % 400 - 200);
	numberOfBalls++;
}

int BallManager::getNumberOfBalls()
{
	numberOfRenderedBalls = 0;
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			numberOfRenderedBalls++;
		}
	}
	return numberOfRenderedBalls;
}