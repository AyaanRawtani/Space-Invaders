#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{

	enum class PlayerState;
	class PlayerModel;
	class PlayerView;
	

	class PlayerController
	{
	private:
		PlayerView* player_view;
		PlayerModel* player_model;

		//float rate_of_fire = 10.f;
		//float elapsed_fire_duration;
		
		void processPlayerInput();
		void moveLeft();
		void moveRight();
		//void updateFireTimer();
		//void processBulletFire();
		void fireBullet();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		


		sf::Vector2f(getPlayerPosition());
	};
}