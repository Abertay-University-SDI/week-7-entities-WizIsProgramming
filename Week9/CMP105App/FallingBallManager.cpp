#include "FallingBallManager.h"

FallingBallManager::FallingBallManager()
{
	window = nullptr;
	textPtr = nullptr;
	numberOfRenderedBalls = 0;
	texture.loadFromFile("gfx/Beach_Ball.png");
	numberOfBalls = 0;
	font.loadFromFile("font/arial.ttf");
}

void FallingBallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0.f,250.f);
			balls[i].setPosition(rand()%window->getSize().x,-100.f);
			return;
		}
	}
}

void FallingBallManager::update(float dt)
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

void FallingBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > window->getSize().y)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void FallingBallManager::render()
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

void FallingBallManager::setWindowPtr(sf::RenderWindow* windowPointer)
{
	window = windowPointer;
}

void FallingBallManager::setTextPtr(sf::Text* textPointer)
{
	textPtr = textPointer;
}

void FallingBallManager::updateText()
{
	textPtr->setFont(font);
	textPtr->setFillColor(sf::Color::Magenta);
	textPtr->setCharacterSize(20);
	textPtr->setString(std::to_string(getNumberOfBalls()));
}

void FallingBallManager::createBall()
{
	balls.push_back(Ball());
	balls[numberOfBalls].setAlive(true);
	balls[numberOfBalls].setPosition(rand()%window->getSize().x,-100.f);
	balls[numberOfBalls].setTexture(&texture);
	balls[numberOfBalls].setSize(sf::Vector2f(100, 100));
	balls[numberOfBalls].setVelocity(0.f,250.f);
	numberOfBalls++;
}

int FallingBallManager::getNumberOfBalls()
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