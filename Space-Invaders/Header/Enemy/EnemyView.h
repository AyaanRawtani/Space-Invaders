#pragma once
#include "SFML/Graphics.hpp"
#include "UIService/UIElement/ImageView.h"

namespace Enemy
{
	class EnemyController;
	class EnemyModel;
	enum class EnemyType;
	
	class EnemyView
	{
	private :
		//const sf::String subzero_texture_path = "assets/textures/subzero.png";
		//const sf::String zapper_texture_path = "assets/textures/enemy_ship_zapper.png";
		//const sf::String ufo_texture_path = "assets/textures/ufo.png";

		const float enemy_sprite_width = 60.f;
		const float enemy_sprite_height = 60.f;

		EnemyController* enemy_controller;
		UI::UIElement::ImageView* enemy_image;
		

		sf::RenderWindow* game_window;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		void initializeImage();
		void createUIElements();
		sf::String getEnemyTexturePath();
		void destroy();
		//void initializeEnemySprite(EnemyType type);
		//void scaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

	};
}
