#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"
#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel();
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}