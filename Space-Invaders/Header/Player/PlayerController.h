#pragma once
#include <SFML/Graphics.hpp>
#include "Collision/ICollider.h"
#include "Player/PlayerModel.h"
#include "Powerups/PowerupConfig.h"

namespace Player
{

	enum class PlayerState;
	class PlayerModel;
	class PlayerView;
	

	class PlayerController : public Collision::ICollider
	{
	private:
		float elapsed_shield_duration;
		float elapsed_rapid_fire_duration;
		float elapsed_tripple_laser_duration;

		float elapsed_fire_duration;
		float elapsed_freeze_duration;

		PlayerView* player_view;
		PlayerModel* player_model;

		//float rate_of_fire = 10.f;
		//float elapsed_fire_duration;
		
		void processPlayerInput();
		void moveLeft();
		void moveRight();
		//void updateFireTimer();
		//void processBulletFire();
		bool processBulletCollision(ICollider* other_collider);
		bool processPowerupCollision(ICollider* other_collider);
		bool processEnemyCollision(ICollider* other_collider);
		void updateFreezeDuration();
		void freezePlayer();

		void updateFireDuration();
		void processBulletFire();
		void fireBullet(bool b_tripple_laser = false);
		void fireBullet(sf::Vector2f position);

		void updatePowerupDuration();

		void disableShield();
		void disableRapidFire();
		void disableTripleLaser();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		
		void reset();

		void decreasePlayerLives();
		inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
		void enableShield();
		void enableRapidFire();
		void enableTripleLaser();

		sf::Vector2f getPlayerPosition();
		PlayerState getPlayerState();
		
		

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}