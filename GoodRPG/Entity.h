#pragma once
#include "SFML\Graphics.hpp"

class Entity {
protected:
	int x = 0;
	int y = 0;
	sf::Sprite sprite;
	Entity();
	Entity(int posX, int posY);
public:
	virtual void Update();
};
