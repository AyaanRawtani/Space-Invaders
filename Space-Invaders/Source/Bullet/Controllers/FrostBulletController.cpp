#include "Bullet/Controllers/FrostBulletController.h"
#include "Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType type, Entity::EntityType owner_type) : BulletController(type, owner_type)
		{

		}

		FrostBulletController::~FrostBulletController()
		{

		}

		void FrostBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(frostbullet_movement_speed);
		}
	}
}