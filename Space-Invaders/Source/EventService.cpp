#include "EventService.h"
#include "GameService.h"
#include "GraphicService.h"

EventService::EventService()
{
	game_window = nullptr;
}

EventService:: ~EventService()
{
	
}

void EventService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{

}

void EventService::processEvents()
{
	if (isGameWindowOpen())
	{
		while (game_window->pollEvent(game_event))
		{
			if (gameWindowWasClosed() || hasQuitGame())
			{
				game_window->close();
			}
		}
	}

}

bool EventService::hasQuitGame()
{
	return (isKeyboardEvent() && pressedEscapeKey());

}

bool EventService::isKeyboardEvent()
{
	return game_event.type == sf::Event::KeyPressed;
}

bool EventService::pressedEscapeKey()
{
	return game_event.key.code == sf::Keyboard::Escape;
}

bool EventService::isGameWindowOpen()
{
	return game_window != nullptr;
}

bool EventService::gameWindowWasClosed()
{
	return game_event.type == sf::Event::Closed;
}
