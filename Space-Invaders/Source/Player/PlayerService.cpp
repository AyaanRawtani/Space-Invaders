#include "Player/PlayerService.h"
#include "Player/PlayerController.h"

namespace Player
{

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete(player_controller);
	}


	void PlayerService::initialize()
	{
		player_controller->initialize();
	}


	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTripleLaser()
	{
		player_controller->enableTrippleLaser();
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

}

