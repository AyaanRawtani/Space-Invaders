#include "Main/GameService.h"
#include "Graphic/GraphicService.h"
#include "Event/EventService.h"
#include "Global/ServiceLocator.h"

namespace Main 
{

	using namespace Global;
	
	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;

	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showMainMenu();
	}
	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();

	}

	void GameService::destroy()
	{

	}

	void GameService::Ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}
	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();
		game_window->display();

	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::setGameState(GameState new_state)
	{
		current_state = new_state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}

	void GameService::showMainMenu()
	{
		setGameState(GameState::MAIN_MENU);
	}
}