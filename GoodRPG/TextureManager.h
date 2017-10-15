#pragma once
#include <SFML\Graphics.hpp>

class TextureManager {
public:
	static void loadTextures() {
		tiles.loadFromFile("tiles.png");
		enemies.loadFromFile("enemies.png");
	};
	static sf::Texture tiles;
	static sf::Texture enemies;
};
