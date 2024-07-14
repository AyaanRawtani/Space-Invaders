#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/EntityConfig.h"


namespace Bullet
{
	enum class BulletType;
	enum class MovementDirection;

	class BulletModel
	{
	private : 
		float movement_speed = 300.f;
		sf::Vector2f bullet_position;

		BulletType bullet_type;
		MovementDirection movement_direction;
		Entity::EntityType owner_type;

	public:

		BulletModel(BulletType bullet_type, Entity::EntityType owner_type);
		~BulletModel();

		void initialize(sf::Vector2f position, MovementDirection direction);

		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);

		BulletType getBulletType();
		

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		Entity::EntityType getOwnerEntityType();

		float getMovementSpeed();
		void setMovementSpeed(float speed);

	};
}