#include "Pig.h"
#include <iostream>


Pig::Pig(int posX, int posY):Entity(posX,posY) {
	Pig::x = posX;
	Pig::y = posY;
	TextureManager tex;
	tex.loadTextures();
	sprite.setTexture(tex.enemies);
	sprite.setTextureRect(sf::IntRect(96 * frame, 0, 96, 96));
	sprite.setPosition(posX, posY);
	srand(clock.getElapsedTime().asMilliseconds());
	rand_num = rand() % 16;
	sprite.setScale(0.75, 0.75);
	sprite.setOrigin(48, 48);
}

void Pig::Update() {
	if (damaging) {
		damageTimer--;
	}

	if (damageTimer != 0 && damaging) {
		Move(0, 2);
	}

	if (damageTimer <= 0) {
		sprite.setColor(sf::Color::White);
		damaging = false;
	}

	feetTimer++;
	timer++;
	UpdateAnim();

	if (timer >= rand_num_Interval) {
		srand(clock.getElapsedTime().asMilliseconds());
		rand_num = rand() % 16;
		rand_num_Interval = rand() % 120;
		timer = 0;
	}

	moving = false;

		if (rand_num == 1) {
			x+=2;
			if (frame != 4 && frame != 5)
			frame = 4;
			moving = true;
		}
		else if(rand_num == 2){
			y+=2;
			if (frame != 0 && frame != 1)
			frame = 0;
			moving = true;
		}
		else if (rand_num == 3) {
			y -= 2;
			if (frame != 2 && frame != 3)
			frame = 2;
			moving = true;
		}
		else if (rand_num == 4) {
			x -= 2;
			if(frame!=6&&frame!=7)
			frame = 6;
			moving = true;
		}
		UpdateAnim();
		sprite.setTextureRect(sf::IntRect(96 * frame, 0, 96, 96));
	sprite.setPosition(x, y);
}

void Pig::Damage() {
	damaging = true;
	damageTimer = 15;
	sprite.setColor(sf::Color::Red);
	health -= 10;
}

void Pig::Move(int x, int y) {
	Entity::x += x;
	Entity::y += y;
}

void Pig::UpdateAnim() {
	if (feetTimer >= 15) {
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
	sprite.setTextureRect(sf::IntRect(96 * frame, 0, 96, 96));
}