#pragma once
#include <SFML/Graphics.hpp>
#include "../Header/UIService/Interface/IUIController.h"
#include "UIService/UIElement/ImageView.h"
#include "UIService/UIElement/ButtonView.h"

namespace UI
{
		namespace MainMenu
		{
			class MainMenuUIController: public UI::UIController::IUIController
			{
			private:
				/*const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";
				const sf::String play_button_texture_path = "assets/textures/play_button.png";
				const sf::String instructions_button_texture_path = "assets/textures/instructions_button.png";
				const sf::String quit_button_texture_path = "assets/textures/quitt_button.png";
				*/

				const float button_width = 400.f;
				const float button_height = 140.f;

				const float play_button_y_position = 500.f;
				const float instructions_button_y_position = 700.f;
				const float quit_button_y_position = 900.f;

				const float background_alpha = 85.f;

				UIElement::ImageView* background_image;
				UIElement::ButtonView* play_button;
				UIElement::ButtonView* instructions_button;
				UIElement::ButtonView* quit_button;

				void createImage();
				void createButtons();

				void initializeBackgroundImage();
				void initializeButtons();

				void registerButtonCallback();
				void playButtonCallback();
				void instructionsButtonCallback();
				void quitButtonCallback();
				void destroy();
				
			public:
				MainMenuUIController();
				~MainMenuUIController();

				void initialize() override;
				void update() override;
				void render() override;
				void show() override;

			
			};
		}
}