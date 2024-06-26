#include "Enemy/Controller/SubzeroController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	

	namespace Controller
	{


		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) 
		{

		}

		SubzeroController::~SubzeroController() { }

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
		}

		void SubzeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}
	}
}