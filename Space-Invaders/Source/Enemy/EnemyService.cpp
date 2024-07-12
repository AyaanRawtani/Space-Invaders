#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Time/TimeService.h"
#include "Enemy/EnemyConfig.h"
#include "Enemy/Controller/ZapperController.h"
#include "Enemy/Controller/SubzeroController.h"
#include "Enemy/Controller/UFOController.h"
#include "Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService() 
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		
	}

	EnemyService::~EnemyService() 
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (EnemyController* enemy : enemy_list)
			enemy->update();

		destroyFlaggedEnemies();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list)
			enemy->render();
	}

	void EnemyService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy();
			spawn_timer = 0.0f;
		}
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();
		enemy_list.push_back(enemy_controller);

		return enemy_controller;

	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 3;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	
	void EnemyService::destroy()
	{
		
		for (int i = 0; i < enemy_list.size(); i++)			
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(enemy_list[i]));
			delete (enemy_list[i]);
		}
		enemy_list.clear();
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		dynamic_cast<ICollider*>(enemy_controller)->disableCollision();
		flagged_enemy_list.push_back(enemy_controller);
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
	}
}