#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Pig.h"
#include "TextureManager.h"
#include "Tile.h"
#include <ctime>


int main()
{
	TextureManager manager;
	manager.loadTextures();
	TextureManager::loadTextures();

	std::vector<Pig> pigs = std::vector<Pig>();

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG");
	window.setSize(sf::Vector2u(1280, 720));

	window.setFramerateLimit(60);

	Player player;
	Pig pig(0,0);
	Pig pig2(0, 0);
	float zoom = 1;
	pigs.push_back(pig);
	pigs.push_back(pig2);
	bool followPlayer = true;
	bool fullscreen = false;
	int pigLimit = 0;
	sf::View view;
	view.setSize(1920, 1080);
	view.setCenter(player.sprite.getPosition());


	window.setView(view);

	while (window.isOpen())
	{
		pigLimit++;
		srand(time(NULL));
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (zoom >= 0.25) {
				view.zoom(0.9f);
				zoom *= 0.9f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (zoom <= 3) {
				view.zoom(1.1f);
				zoom *= 1.1f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
			if (pigLimit >= 60) {
				pigs.push_back(*new Pig(0, 0));
				pigLimit = 0;
			}
		}

		if (event.type == event.MouseButtonReleased) {

			for (int i = 0; i < pigs.size(); i++) {
				if (pigs.at(i).sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds())) {
					pigs.at(i).Damage();
					pigs.at(i).Move(0, -30);
					if (pigs.at(i).health <= 0) {
						pigs.erase(pigs.begin() + i);
					}
				}
			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
			fullscreen = !fullscreen;
			if (!fullscreen) {
				window.create(sf::VideoMode(1920, 1080), "RPG", sf::Style::Fullscreen);
			}
			else {
				window.create(sf::VideoMode(1920, 1080), "RPG");
			}
			window.setFramerateLimit(60);
		}

		player.Update();
		if (followPlayer) {
			view.setCenter(player.sprite.getPosition());
		}
		window.setView(view);
		window.clear();
		for (int x = 0; x < 128; x++) {
			for (int y = 0; y < 128; y++) {
				sf::Sprite sprite(manager.tiles, sf::IntRect(0, 0, 16, 16));
				sprite.setScale(5,5);
				Tile tile(sprite, x*80-(64*80), y*80-(64*80));
				if(!(tile.sprite.getPosition().x < (view.getCenter().x-(1500*zoom))) && !(tile.sprite.getPosition().x > (view.getCenter().x + 1000 * zoom)) && !(tile.sprite.getPosition().y < (view.getCenter().y - 1000 * zoom)) && !(tile.sprite.getPosition().y > (view.getCenter().y + 1500 * zoom)))
				window.draw(tile.sprite);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		}

		for (int i = 0; i < pigs.size(); i++) {
			srand(time(NULL));
			pigs.at(i).Update();
			window.draw(pigs.at(i).sprite);
		}
		window.draw(player.sprite);
		window.display();
	}

	return 0;
}