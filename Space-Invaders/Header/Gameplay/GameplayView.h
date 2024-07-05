#pragma once
#include <SFML/Graphics.hpp>
#include "UIService/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:
		const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";

		sf::RenderWindow* game_window;
		sf::Texture background_texture;
		sf::Sprite background_sprite;

		//UI::UIElement::ImageView* gameplay_image;

		void initializeBackgroundSprite();
		void scaleBackgroundSprite();

		//void initializeImage();
		//void createUIElements();
		//sf::String getGameplayTexturePath();
		//void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}
