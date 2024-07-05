#include "Bullet/BulletController.h"
#include "Bullet/BulletModel.h"
#include "Bullet/BulletConfig.h"
#include "Bullet/BulletView.h"
#include "Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	BulletController::BulletController(BulletType type, Entity::EntityType owner_type)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(type);	
	}

	BulletController::~BulletController()
	{
		delete(bullet_view);
		delete(bullet_model);
	}
	
	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}
	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		handleOutOfBounds();

	}
	void BulletController::render()
	{
		bullet_view->render();
	}

	void BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			moveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);

	}
	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();

		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);

	}
	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bulletPosition = getProjectilePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return Entity::EntityType();
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}

	
}