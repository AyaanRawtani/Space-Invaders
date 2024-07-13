#pragma once
#include "UIService/Interface/IUIController.h"
#include "UIService/UIElement/ImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public UIController::IUIController
		{
		private :
			const float splash_screen_duration = 2.0f;
			float elapsed_duration = 0.0f;
			const float logo_width = 600.f;
			const float logo_height = 134.f;

			UIElement::ImageView* outscal_logo_view;

			void initializeOutscalLogo();
			void updateTimer();
			void showMainMenu();
			sf::Vector2f getLogoPosition();

		public :
			SplashScreenUIController();
			~SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}