#pragma once
#include "Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController : public BulletController
		{
		private:
			const float frostbullet_movement_speed = 500.f;

		public:
			FrostBulletController(BulletType type);
			~FrostBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}
