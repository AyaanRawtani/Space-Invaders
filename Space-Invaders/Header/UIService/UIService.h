#pragma once
#include "../UIService/MainMenuUIController/MainMenuUIController.h"
#include "../UIService/Interface/IUIController.h"
#include "UIService/GameplayUIController/GameplayUIController.h"
#include "UIService/SpalshScreenUI/SplashScreenUIController.h"

namespace UI
{
	using namespace UIController;

	class UIService 
	{
	private:

		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splash_screen_controller;


		void createControllers();
		void initializeControllers();

		UIController::IUIController* getCurrentUIController();
		

		void destroy();

	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();
		
	};
}
