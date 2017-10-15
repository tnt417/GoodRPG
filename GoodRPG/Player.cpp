#include "Player.h"

Player::Player() {
	tex.loadFromFile("knight_anim.png");
	sprite.setTexture(tex);
	sprite.setOrigin(48, 48);
	frame = 2;
	feetTimer = 0;
	diag = false;
}

Player::~Player() {

}

void Player::Update() {
		moving = false;
	feetTimer++;

	HandleEvents();

	UpdateAnim();

	sprite.setTextureRect(sf::IntRect(frame*96,0,96,96));
}

void Player::HandleEvents() {
	for (int i = 0; i < 512; i++) {
	lastKeys[i] = keys[i];
}
	keys[sf::Keyboard::W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	keys[sf::Keyboard::A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	keys[sf::Keyboard::S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	keys[sf::Keyboard::D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	if (((keys[sf::Keyboard::S] || keys[sf::Keyboard::W]) && (keys[sf::Keyboard::A] && keys[sf::Keyboard::D])) || (keys[sf::Keyboard::A] || keys[sf::Keyboard::D]) && ((keys[sf::Keyboard::S] || keys[sf::Keyboard::W]))) {
		diag = true;
	}
	else {
		diag = false;
	}

	if (keys[sf::Keyboard::W]) {
		if(!keys[sf::Keyboard::A] && !keys[sf::Keyboard::D])
		sprite.move(0, -5);
		else
		sprite.move(0, -4);
		moving = true;
		if (frame != 2 && frame != 3)
			if (!keys[sf::Keyboard::A] && !keys[sf::Keyboard::D] && !diag) {
				frame = 2;
				diag = true;
			}
	}

	if (keys[sf::Keyboard::S]) {
		if (!keys[sf::Keyboard::A] && !keys[sf::Keyboard::D])
		sprite.move(0, 5);
		else
			sprite.move(0, 4);
		moving = true;
		if (frame != 0 && frame != 1)
			if (!keys[sf::Keyboard::A] && !keys[sf::Keyboard::D] && !diag) {
				frame = 0;
				diag = true;
			}
	}

	if (keys[sf::Keyboard::A]) {
		if (!keys[sf::Keyboard::S] && !keys[sf::Keyboard::W])
		sprite.move(-5, 0);
		else
			sprite.move(-4, 0);
		moving = true;
		if (frame != 6 && frame != 7)
			if (!keys[sf::Keyboard::S] && !keys[sf::Keyboard::W] && !diag) {
				frame = 6;
				diag = true;
			}
	}

	if (keys[sf::Keyboard::D]) {
		if (!keys[sf::Keyboard::W] && !keys[sf::Keyboard::S])
		sprite.move(5, 0);
		else
			sprite.move(4, 0);
		moving = true;
		if (frame != 4 && frame != 5)
			if (!keys[sf::Keyboard::W] && !keys[sf::Keyboard::S] && !diag) {
				frame = 4;
				diag = true;
			}
	}
	for (int i = 0; i < 512; i++) {
		lastKeys[i] = false;
	}
}

void Player::UpdateAnim() {
	if (feetTimer >= 25) {
		feetTimer = 0;
		if (moving) {
			if (frame == 4) {
				frame = 5;
			}
			else
				if (frame == 5) {
					frame = 4;
				}
				else
					if (frame == 2) {
						frame = 3;
					}
					else
						if (frame == 3) {
							frame = 2;
						}
						else if (frame == 0) {
							frame = 1;
						}
						else if (frame == 1) {
							frame = 0;
						}
						else if (frame == 6) {
							frame = 7;
						}
						else if (frame == 7) {
							frame = 6;
						}
		}
	}
}
