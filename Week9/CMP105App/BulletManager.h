#pragma once
#include "Player.h"
#include "Bullet.h"
#include <vector>
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void setPlayer(Player* player);
	void setInput(Input* input);
	void setWindow(sf::RenderWindow* window);
	void handleInput();
	void update();
	void deathCheck();
	void createBullet();
private:
	Player* playerPtr;
	Input* inputPtr;
	sf::RenderWindow* windowPtr;
	std::vector<Bullet> bullets;
	int numberOfBullets;

};

