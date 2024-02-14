#include "../../header/Bullet/Controller/LaserBulletController.h"

namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType type) : BulletController(type) { }

		LaserBulletController::~LaserBulletController() { }

		void LaserBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}