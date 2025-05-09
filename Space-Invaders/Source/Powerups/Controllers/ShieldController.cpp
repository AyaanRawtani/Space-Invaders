#include "Powerups/Controllers/ShieldController.h"
#include "Player/PlayerController.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Player;
	using namespace Global;

	namespace Controller
	{
		ShieldController::ShieldController(PowerupType type) : PowerupController(type)
		{

		}

		ShieldController::~ShieldController()
		{

		}

		void ShieldController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableShield();
		}

		void ShieldController::onCollected()
		{

		}
	}
}