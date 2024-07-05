#pragma once
#include "Projectile/IProjectile.h"
#include "Bullet/BulletConfig.h"
#include "Entity/EntityConfig.h"

namespace Bullet
{
	
	class BulletView;
	class BulletModel;
	enum class BulletType;
	//enum class EntityType;

	class BulletController : public Projectile::IProjectile
	{
	protected :
		BulletView* bullet_view;
		BulletModel* bullet_model;

		void updateProjectilePosition() override;
		void moveUp();
		void moveDown();
		void handleOutOfBounds();

		Entity::EntityType getOwnerEntityType();

	public :

		BulletController(BulletType type, Entity::EntityType owner_type);
		virtual ~BulletController() override;
		void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void update() override;
		void render() override;

		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();

	};

}