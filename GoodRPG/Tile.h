#pragma once
#include <SFML\Graphics.hpp>

class Tile{
public:
	int x;
	int y;
	int width;
	int height;
	sf::Sprite sprite;
	Tile(sf::Sprite sprite, int x, int y);
	~Tile();
private:
};
