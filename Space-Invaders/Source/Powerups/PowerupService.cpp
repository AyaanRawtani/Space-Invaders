#include "Powerups/PowerupService.h"
#include "Powerups/PowerupController.h"
#include "Powerups/PowerupConfig.h"
#include "Global/ServiceLocator.h"
#include "Powerups/Controllers/OutscalBombController.h"
#include "Powerups/Controllers/RapidFireController.h"
#include "Powerups/Controllers/ShieldController.h"
#include "Powerups/Controllers/TripleLaserController.h"

namespace Powerup
{

	using namespace Global;
	using namespace Controller;
	using namespace Collectible;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize()
	{

	}

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->update();
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

		case::Powerup::PowerupType::TRIPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPLE_LASER);

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

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
		delete(powerup_controller);
	}
}