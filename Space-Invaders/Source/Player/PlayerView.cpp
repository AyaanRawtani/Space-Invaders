#include "Player/PlayerView.h"
#include "Global/ServiceLocator.h"
#include "Player/PlayerController.h"
#include "UIService/UIElement/ImageView.h"
#include "Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() { createUIElements(); }
	PlayerView::~PlayerView() { destroy(); }

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//initializePlayerSprite();
		initializeImage();
	}

	/*void PlayerView::initializePlayerSprite()
	{
		if (player_texture.loadFromFile(player_texture_path))
		{
			player_sprite.setTexture(player_texture);
			scalePlayerSprite();
		}
	}

	void PlayerView::scalePlayerSprite()
	{
		player_sprite.setScale(

			static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
			static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y);

	}*/


	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(getPlayerTexturePath(), player_sprite_height, player_sprite_width, player_controller->getPlayerPosition());
	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
		player_image->update();
	}
	void PlayerView::render()
	{
		player_image->render();
	}

	void PlayerView::destroy()
	{
		delete(player_image);
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_image->getSprite();
	}

}