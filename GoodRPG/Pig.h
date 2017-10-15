#pragma once

#include "Entity.h"
#include "TextureManager.h"
#include <time.h>
#include "SFML/System.hpp"


class Pig:public Entity {

public:
	Entity::x;
	Entity::y;
	sf::Sprite sprite;
	struct Pig(int posX, int posY);
	void Update();
	void Damage();
	int health = 100;
	sf::Clock clock;
	int timer = 0;
	int damageTimer = 30;
	bool damaging = false;
	int rand_num = rand()%8;
	int frame = 0;
	bool moving = false;
	int feetTimer = 0;
	int rand_num_Interval = 120;
	void UpdateAnim();
	void Move(int x, int y);
};
