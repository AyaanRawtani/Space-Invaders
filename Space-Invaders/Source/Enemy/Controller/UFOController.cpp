#include "Enemy/Controller/UFOController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"
#include "Bullet/BulletController.h"
#include "Collision/ICollider.h" 
#include "Entity/EntityConfig.h"

namespace Enemy
{
    using namespace Global;
    using namespace Bullet;
    using namespace Collision;
    using namespace Entity;

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

        void UFOController::onCollision(ICollider* other_collider)
        {
            EnemyController::onCollision(other_collider);
            BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

            if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
            {
                ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(getRandomPowerupType(), enemy_model->getEnemyPosition());
                return;
            }
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

        void UFOController::fireBullet() {}


        Powerup::PowerupType UFOController::getRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
            return static_cast<Powerup::PowerupType>(random_value);
        }




        void UFOController::destroy()
        {

            EnemyController::destroy();
        }
    }
}