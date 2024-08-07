#pragma once
#include "Enemy/EnemyController.h"
#include "Powerups/PowerupConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class UFOController : public EnemyController
		{
		private : 
			void move() override;
			void moveLeft();
			void moveRight();

			void fireBullet() override;
			Powerup::PowerupType getRandomPowerupType();

		public :
			UFOController(EnemyType type);
			~UFOController();

			void initialize() override;
			
		};
	}
}
