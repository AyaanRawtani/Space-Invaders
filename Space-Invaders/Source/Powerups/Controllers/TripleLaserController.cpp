#include "Powerups/Controllers/TripleLaserController.h"
#include "Player/PlayerController.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Player;
	using namespace Global;

	namespace Controller
	{
		TripleLaserController::TripleLaserController(PowerupType type) : PowerupController(type)
		{

		}

		TripleLaserController::~TripleLaserController()
		{

		}

		void TripleLaserController::applyPowerup()
		{
			ServiceLocator::getInstance()->getPlayerService()->enableTripleLaser();
		}

		void TripleLaserController::onCollected()
		{

		}
	}
}