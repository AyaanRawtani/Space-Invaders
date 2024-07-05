#pragma once
#include "../UIService/MainMenuUIController/MainMenuUIController.h"
#include "../UIService/Interface/IUIController.h"

namespace UI
{
	using namespace UIController;
	class MainMenu::MainMenuUIController;
	
	class UIService 
	{
	private:

		MainMenu::MainMenuUIController* main_menu_controller;
		void createControllers();
		void initializeControllers();

		IUIController* getCurrentUIController();
		

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
