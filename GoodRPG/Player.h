#pragma once
#include <SFML\Graphics.hpp>

class Player {

public:

	Player();
	~Player();
	void Update();
	void UpdateAnim();
	void HandleEvents();

	int x;
	int y;
	int frame;
	int feetTimer;
	bool moving;
	bool diag;
	int movingTimer;

	bool keys[512];
	bool lastKeys[512];

	sf::Texture tex;
	sf::Sprite sprite;

private:


};
