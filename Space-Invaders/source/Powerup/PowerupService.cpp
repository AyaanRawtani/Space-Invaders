#include "../../header/Powerup/PowerupService.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Powerup/Controller/OutscalBombController.h"
#include "../../header/Powerup/Controller/RapidFireController.h"
#include "../../header/Powerup/Controller/ShieldController.h"
#include "../../header/Powerup/Controller/TrippleLaserController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Controller;

	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { destroy(); }

	void PowerupService::initialize() { }

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->update();

		if (ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton())
		{
			spawnPowerup(PowerupType::SHIELD, sf::Vector2f(100.f, 50.f));
		}
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->render();
	}

	PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		switch (powerup_type)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);

		powerup_controller->initialize(position);
		powerup_list.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++) delete (powerup_list[i]);
	}
}