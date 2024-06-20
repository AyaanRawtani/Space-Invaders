#include "Enemy/EnemyView.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyController.h"
#include "Graphic/GraphicService.h"

namespace Enemy 
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() {}
	EnemyView::~EnemyView() {}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}

	void EnemyView::initializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path))
		{
			//printf("initializing enemy sprite \n");
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
		//printf("failed to initialize enemy sprite \n");
		
	}

	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale
		(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}



}