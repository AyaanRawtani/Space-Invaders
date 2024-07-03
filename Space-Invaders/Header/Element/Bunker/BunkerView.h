#pragma once
#include <SFML/Graphics.hpp>
#include "UIService/UIElement/ImageView.h"

namespace Element
{
	namespace Bunker
	{
		class BunkerController;

		class BunkerView
		{
		private :
			const float bunker_sprite_width = 80.f;
			const float bunker_sprite_height = 80.f;

			BunkerController* bunker_controller;
			UI::UIElement::ImageView* bunker_image;

			sf::RenderWindow* game_window;

			sf::Texture bunker_texture;
			sf::Sprite bunker_sprite;

			const sf::String bunker_texture_path = "assets/textures/bunker.png";

			void initializeImage();
			void createUIElements();
			sf::String getBunkertexturePath();
			void destroy();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();


		};
	}
}