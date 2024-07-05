#include "Bullet/BulletService.h"
#include "Bullet/BulletController.h"
#include "Bullet/BulletConfig.h"
#include "Bullet/Controllers/FrostBulletController.h"
#include "Bullet/Controllers/LaserBulletController.h"
#include "Bullet/Controllers/TorpedoController.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;


	BulletService::BulletService()
	{

	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::initialize()
	{

	}

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++)bullet_list[i]->update();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++)bullet_list[i]->render();
	}

	void BulletService::reset()
	{
	}

	BulletController* BulletService::createBullet(BulletType bullet_type, Entity::EntityType owner_type)
	{
		BulletController* ptr = nullptr;

		switch (bullet_type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			ptr =  new LaserBulletController(Bullet::BulletType::LASER_BULLET, Entity::EntityType::BULLET);
			return ptr;

		case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, Entity::EntityType::BULLET);

		case::Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, Entity::EntityType::BULLET);
		}
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)delete(bullet_list[i]);
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(bullet_type, owner_type);

		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller),bullet_list.end());
		delete(bullet_controller);
	}
}