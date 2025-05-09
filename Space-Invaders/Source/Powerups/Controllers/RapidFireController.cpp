#include "Powerups/Controllers/RapidFireController.h"
#include "Player/PlayerController.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Player;
	using namespace Global;

	namespace Controller
	{
		RapidFireController::RapidFireController(PowerupType type) : PowerupController(type)
		{

		}

		RapidFireController::~RapidFireController()
		{

		}

		void RapidFireController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableRapidFire();
		}

		void RapidFireController::onCollected()
		{

		}
	}
}