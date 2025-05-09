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
		
	}

	

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
		
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
		enemy_image->update();
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	const sf::Sprite EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	void EnemyView::destroy()
	{
		delete(enemy_image);
	}



}