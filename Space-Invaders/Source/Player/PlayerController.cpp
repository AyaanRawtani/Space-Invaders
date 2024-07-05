#include "Player/PlayerController.h"
#include "Event/EventService.h"
#include "Global/ServiceLocator.h"
#include "Player/PlayerView.h"
#include "Player/PlayerModel.h"
#include <algorithm>

namespace Player
{
	using namespace Global;
	using namespace Event;

	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
		

	}
	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
		
	
	}

	void PlayerController::update()
	{
		processPlayerInput();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if(event_service->pressedLeftMouseButton()) fireBullet();
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::fireBullet()
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET, player_model->getPlayerPosition() + player_model->barrel_position_offset,
			Bullet::MovementDirection::UP);
	}

	/*void PlayerController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void PlayerController::processBulletFire()
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f; 
		}
	}*/
}