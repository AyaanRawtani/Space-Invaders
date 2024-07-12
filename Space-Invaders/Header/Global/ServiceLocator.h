#pragma once
#include "Event/EventService.h"
#include "Graphic/GraphicService.h"
#include "Time/TimeService.h"
#include "Player/PlayerService.h"
#include "UIService/UIService.h"
#include "Enemy/EnemyService.h"
#include "Gameplay/GameplayService.h"
#include "Element/ElementService.h"
#include "Sound/SoundService.h"
#include "Bullet/BulletService.h"
#include "Powerups/PowerupService.h"
#include "Collision/CollisionService.h"


namespace Global
{

	class ServiceLocator
	{
	private:
		Graphic::GraphicService* graphic_service;
		Event::EventService* event_service;
		Player::PlayerService* player_service;
		Time::TimeService* time_service;
		UI::UIService* ui_service;
		Enemy::EnemyService* enemy_service;
		Gameplay::GameplayService* gameplay_service;
		Element::ElementService* element_service;
		Sound::SoundService* sound_service;
		Bullet::BulletService* bullet_service;
		Powerup::PowerupService* powerup_service;
		Collision::CollisionService* collision_service;


		ServiceLocator();
		~ServiceLocator();

		void createServices();
		void clearAllServices();

	public:

		static ServiceLocator* getInstance();
		void initialize();
		void update();
		void render();

		Graphic::GraphicService* getGraphicService();
		Event::EventService* getEventService();
		Player::PlayerService* getPlayerService();
		Time::TimeService* getTimeService();
		UI::UIService* getUIService();
		Enemy::EnemyService* getEnemyService();
		Gameplay::GameplayService* getGameplayService();
		Element::ElementService* getElementService();
		Sound::SoundService* getSoundService();
		Bullet::BulletService* getBulletService();
		Powerup::PowerupService* getPowerupService();
		Collision::CollisionService* getCollisionService();

		void deleteServiceLocator();
	};

}