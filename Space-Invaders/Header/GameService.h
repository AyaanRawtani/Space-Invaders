#pragma once
#include<SFML/Graphics.hpp>
#include "ServiceLocator.h"

class GameService
{
private:
	ServiceLocator* service_locator;
	sf::RenderWindow* game_window;

	void initialize();
	void initializeVariables();
	void destroy();

public:
	GameService();
	~GameService();
	void Ignite();
	void update();
	void render();
	bool isRunning();
		

};
