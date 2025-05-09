#pragma once
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class SubzeroController: public EnemyController
		{
		private:
			float vertical_movement_speed = 100.f;
			const float subzero_rate_of_fire = 2.5f;

			void move() override;
			void moveDown();
			void destroy() override;
		public:
			//SubzeroController();
			SubzeroController(EnemyType type);
			~SubzeroController();

			void initialize() override;
			void fireBullet();

			

		};
	}
}