#pragma once
#include <SFML/Graphics.hpp>
#include "XBOX360CONTROLLER.h"

class Game {
public:
	void run();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	Xbox360Controller m_controller;

	void background();
};