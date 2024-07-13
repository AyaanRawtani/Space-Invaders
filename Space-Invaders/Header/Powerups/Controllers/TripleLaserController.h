#pragma once
#include "Powerups/PowerupController.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	namespace Controller
	{
		class TripleLaserController : public PowerupController
		{
		public :
			TripleLaserController(PowerupType type);
			virtual ~TripleLaserController();
			void applyPowerup();

			void onCollected() override;
		};
	}
}