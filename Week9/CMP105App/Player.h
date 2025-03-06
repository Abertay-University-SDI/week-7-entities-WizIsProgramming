#pragma once
#include "Framework/GameObject.h"
#include "Framework/VectorHelper.h"
#include <iostream>
class Player: public GameObject
{
public:
	Player();
	~Player();
	void handleInput();
	void update(float dt);
	void setLastDir();
	sf::String getLastDir();
private:
	sf::Vector2f moveVector;
	const float maxSpeed = 250.f; //max move speed in px per second

	sf::Texture texture;

	sf::String lastDirection;
};

