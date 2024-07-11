#include "Powerups/Controllers/OutscalBombController.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	namespace Controller
	{
		OutscalBombController::OutscalBombController(PowerupType type) :PowerupController(type)
		{

		}

		OutscalBombController::~OutscalBombController()
		{

		}

		void OutscalBombController::applyPowerup()
		{
			ServiceLocator::getInstance()->getEnemyService()->reset();
		}

	
	}
}