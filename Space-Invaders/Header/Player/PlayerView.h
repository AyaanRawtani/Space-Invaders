#pragma once
#include <SFML/Graphics.hpp>
#include "UIService/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		const sf::String player_texture_path = "assets/textures/player_ship.png";
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;

		UI::UIElement::ImageView* player_image;

		sf::RenderWindow* game_window;

		sf::Texture player_texture;
		sf::Sprite player_sprite;

		void createUIElements();
		void initializeImage();
		sf::String getPlayerTexturePath();
		void destroy();

		//void initializePlayerSprite();
		//void scalePlayerSprite();

		PlayerController* player_controller;

	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

	};
}
