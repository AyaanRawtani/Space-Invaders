#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
	};

	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
		sf::Vector2f enemy_position;
		bool enemy_alive;
		MovementDirection movement_direction;

	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.0f, 950.0f);

		const float vertical_travel_distance = 100.0f;
		const float enemy_movement_speed = 250.0f;


		EnemyModel();
		~EnemyModel();

		void initialize();


		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);


		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		bool getEnemyAlive();
		void setEnemyAlive(bool alive);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

	};
}