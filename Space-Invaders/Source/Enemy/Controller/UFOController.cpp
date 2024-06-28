#include "Enemy/Controller/UFOController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"

namespace Enemy
{
    using namespace Global;

	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{

		}

		UFOController::~UFOController()
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();	
		}

        void UFOController::move()
        {

            switch (enemy_model->getMovementDirection())
            {

            case::Enemy::MovementDirection::LEFT:
                moveLeft();
                break;

            case::Enemy::MovementDirection::RIGHT:
                moveRight();
                break;

            }
        }

        void UFOController::moveLeft()
        {

            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

            currentPosition.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

            if (currentPosition.x <= enemy_model->left_most_position.x)
            {
                enemy_model->setMovementDirection(MovementDirection::RIGHT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {
                enemy_model->setEnemyPosition(currentPosition);
            }
        }


        void UFOController::moveRight()
        {

            sf::Vector2f currentPosition = enemy_model->getEnemyPosition();


            currentPosition.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();


            if (currentPosition.x >= enemy_model->right_most_position.x)
            {

                enemy_model->setMovementDirection(MovementDirection::LEFT);
                enemy_model->setReferencePosition(currentPosition);
            }
            else
            {

                enemy_model->setEnemyPosition(currentPosition);
            }
        }

        void UFOController::fireBullet()
        {

        }

        Powerup::PowerupType UFOController::getRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
            return static_cast<Powerup::PowerupType>(random_value);
        }
	}
}