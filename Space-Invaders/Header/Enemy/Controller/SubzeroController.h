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

			void move() override;
			void moveDown();

		public:
			//SubzeroController();
			SubzeroController(EnemyType type);
			~SubzeroController();

			void initialize() override;

		};
	}
}