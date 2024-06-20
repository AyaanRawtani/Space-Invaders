#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy
{


	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
		sf::Vector2f enemy_position;
		bool enemy_alive;

	public:

		EnemyModel();
		~EnemyModel();

		void initialize();


		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);


		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		bool getEnemyAlive();
		void setEnemyAlive(bool alive);

	};
}