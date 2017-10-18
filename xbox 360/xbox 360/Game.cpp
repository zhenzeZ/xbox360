#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void Game::run() {

	background();

	sf::RenderWindow window(sf::VideoMode(900, 600), "Xbox360Controller");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		m_controller.CheckButton();
		m_controller.update();

		window.clear(sf::Color(0, 0, 0, 0));
		window.draw(m_sprite);
		m_controller.render(window);

		window.display();

	}


}

void Game::background() {

	if (!m_texture.loadFromFile("./ASSETS/IMAGES/controller.jpg")) {
		std::string s("Error loading texture");
		throw std::exception(s.c_str());
	}
	// load the image from file, and check loading

	m_sprite.setTexture(m_texture); // display image to screen
}
