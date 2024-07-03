#include "Enemy/EnemyView.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyController.h"
#include "Graphic/GraphicService.h"
#include "Enemy/EnemyConfig.h"
#include "Enemy/EnemyModel.h"
#include "Global/Config.h"


namespace Enemy 
{
	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;

	EnemyView::EnemyView() { createUIElements(); }
	EnemyView::~EnemyView() { destroy(); }

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage();
		//initializeEnemySprite(enemy_controller->getEnemyType());
	}

	/*void EnemyView::initializeEnemySprite(EnemyType type)
	{
		switch (type)
		{

		case::Enemy::EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(subzero_texture_path))
			{
					//printf("initializing enemy sprite \n");
					enemy_sprite.setTexture(enemy_texture);
					scaleEnemySprite();
			}
			break;

		case::Enemy::EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(zapper_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleEnemySprite();
			}
			break;

		case::Enemy::EnemyType::UFO:
			if (enemy_texture.loadFromFile(ufo_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);
				scaleEnemySprite();
			}
				//printf("failed to initialize enemy sprite \n");
		}
		
	}

	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale
		(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}*/

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_height, enemy_sprite_width, enemy_controller->getEnemyPosition());
	}
	
	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;
			

		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;
			

		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
			
		}
	}

	void EnemyView::update()
	{
		enemy_image->update();
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	void EnemyView::destroy()
	{
		delete(enemy_image);
	}



}