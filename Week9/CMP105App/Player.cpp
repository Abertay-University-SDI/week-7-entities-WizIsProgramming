#include "Player.h"

Player::Player()
{
	//Set start position
	setPosition(sf::Vector2f(250.f, 250.f));

	//Set up how the player appears
	setSize(sf::Vector2f(100.f, 100.f));
	texture.loadFromFile("gfx/MushroomTrans.png");
	setTexture(&texture);

	lastDirection = "right";
}

Player::~Player()
{

}

void Player::handleInput()
{
	float leftRight = (input->isKeyDown(sf::Keyboard::D) - input->isKeyDown(sf::Keyboard::A));
	float upDown = (input->isKeyDown(sf::Keyboard::S) - input->isKeyDown(sf::Keyboard::W));
	moveVector = VectorHelper::normalise(sf::Vector2f(leftRight, upDown));
}

void Player::update(float dt)
{
	move(moveVector * maxSpeed * dt);
	
}

void Player::setLastDir()
{
	if (velocity.x < 0)
	{
		lastDirection = "left";
	}
	if (velocity.y > 0)
	{
		lastDirection = "right";
	}
}

sf::String Player::getLastDir()
{
	return lastDirection;
}