#pragma once
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	namespace Controller
	{
		class ZapperController : public EnemyController
		{
		private :
			float vertical_movement_speed = 100.f;
			float hortizontal_movement_speed = 250.f;

			const float zapper_rate_of_fire = 2.f;

			void move() override;
			void moveDown();
			void moveLeft();
			void moveRight();

			void destroy() override;

		public :
			ZapperController(EnemyType type);
			~ZapperController();

			void initialize() override;
			void fireBullet();

		};
	}
}