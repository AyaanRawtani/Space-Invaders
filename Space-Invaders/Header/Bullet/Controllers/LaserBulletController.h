#pragma once
#include "Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class LaserBulletController : public BulletController
		{
		public :
			LaserBulletController(BulletType type);
			~LaserBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}
