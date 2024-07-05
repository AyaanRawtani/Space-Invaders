#include "Player/PlayerController.h"
#include "Event/EventService.h"
#include "Global/ServiceLocator.h"
#include "Player/PlayerView.h"
#include "Player/PlayerModel.h"
#include "Bullet/BulletController.h"
#include "Enemy/EnemyController.h"
#include "Powerups/PowerupController.h"
#include <algorithm>

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Bullet;
	using namespace Enemy;
	using namespace Powerup;

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
		switch (player_model->getPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			processPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			updateFreezeDuration();
			break;
		}

		updatePowerupDuration();
		updateFireDuration();
		player_view->update();
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

	void PlayerController::reset()
	{
		player_model->reset();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if (processPowerupCollision(other_collider))
			return;
		if (processBulletCollision(other_collider))
			return;

		processEnemyCollision(other_collider);
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	int PlayerController::getPlayerScore()
	{
		return player_model->getPlayerScore();
	}




	

	bool PlayerController::processBulletCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller && bullet_controller->getOwnerEntityType() != Entity::EntityType::PLAYER)
		{
			if (bullet_controller->getBulletType() == BulletType::FROST_BULLET)
			{
				player_model->setPlayerState(PlayerState::FROZEN);
				player_model->elapsed_freeze_duration = player_model->freeze_duration;
			}
			else ServiceLocator::getInstance()->getGameplayService()->restart();
			return true;
		}

		return false;
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);
		if (enemy_controller)
		{
			ServiceLocator::getInstance()->getGameplayService()->restart();
			return true;
		}
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		PowerupController* powerup_controller = dynamic_cast<PowerupController*>(other_collider);
		if (powerup_controller)
		{
			return true;
		}
		return false;
	}

	void PlayerController::updatePowerupDuration()
	{
		if (player_model->elapsed_shield_duration > 0)
		{
			player_model->elapsed_shield_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_shield_duration <= 0)
				disableShield();
		}

		if (player_model->elapsed_rapid_fire_duration > 0)
		{
			player_model->elapsed_rapid_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_rapid_fire_duration <= 0)
				disableRapidFire();
		}

		if (player_model->elapsed_triple_laser_duration > 0)
		{
			player_model->elapsed_triple_laser_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_triple_laser_duration <= 0)
				disableTripleLaser();
		}
	}

	void PlayerController::enableShield()
	{
		player_model->elapsed_shield_duration = player_model->shield_powerup_duration;
		player_model->setShieldState(true);
	}

	void PlayerController::disableShield()
	{
		player_model->setShieldState(false);
	}

	void PlayerController::enableRapidFire()
	{
		player_model->elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire()
	{
		player_model->setRapidFireState(false);
	}

	void PlayerController::enableTrippleLaser()
	{
		player_model->elapsed_triple_laser_duration = player_model->triple_laser_powerup_duration;
		player_model->setTripleFireState(true);
	}

	void PlayerController::disableTripleLaser()
	{
		player_model->setTripleFireState(false);
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

		if (event_service->pressedLeftMouseButton())
		{
			processBulletFire();
		}
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

	void PlayerController::updateFireDuration()
	{
		if (player_model->elapsed_fire_duration >= 0)
		{
			player_model->elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}
	}

	void PlayerController::updateFreezeDuration()
	{
		if (player_model->elapsed_freeze_duration > 0)
		{
			player_model->elapsed_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_freeze_duration <= 0)
				player_model->setPlayerState(PlayerState::ALIVE);
		}
	}

	void PlayerController::processBulletFire()
	{
		if (player_model->elapsed_fire_duration > 0) return;

		if (player_model->isTripleLaserEnabled())
			fireBullet(true);

		else fireBullet();

		if (player_model->isRapidFireEnabled())
			player_model->elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;

		else player_model->elapsed_fire_duration = player_model->fire_cooldown_duration;
	}

	void PlayerController::fireBullet(bool b_triple_laser)
	{
		sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->barrel_position_offset;
		fireBullet(bullet_position);

		if (b_triple_laser)
		{
			fireBullet(bullet_position + player_model->second_weapon_position_offset);
			fireBullet(bullet_position + player_model->third_weapon_position_offset);
		}
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
			player_model->getEntityType(), position, Bullet::MovementDirection::UP);
	}

}