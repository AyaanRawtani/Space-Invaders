#include "Powerups/PowerupController.h"
#include "Powerups/PowerupModel.h"
#include "Powerups/PowerupView.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete(powerup_model);
		delete(powerup_view);
	}

	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_model->initialize(position);
		powerup_view->initialize(this);
	}

	void PowerupController::update()
	{
		updatePowerupPosition();
		powerup_view->update();
	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::onCollected()
	{

	}

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f current_position = powerup_model->getPowerupPosition();
		current_position.y += powerup_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(current_position);
	}

	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f powerupPosition = getCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}

	sf::Vector2f PowerupController::getCollectiblePosition()
	{
		return powerup_model->getPowerupPosition();
	}

	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}


}

