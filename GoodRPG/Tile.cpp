#include "Tile.h"

Tile::Tile(sf::Sprite sprite, int x, int y) {
	sprite.setPosition(x, y);
	
	Tile::sprite = sprite;
}

Tile::~Tile() {

}