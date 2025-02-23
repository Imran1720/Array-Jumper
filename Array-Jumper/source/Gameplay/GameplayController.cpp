#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;


namespace Gameplay
{

	GameplayController::GameplayController()
	{
	}

	GameplayController::~GameplayController()
	{
	}

	void GameplayController::initialize()
	{
	}

	void GameplayController::update()
	{
		onPositionChanged(ServiceLocator::getInstance()->getPlayerService()->GetPlayerPosition());
	}

	void GameplayController::render()
	{
	}

	void GameplayController::ProcessObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->TakeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	bool GameplayController::isObstacle(BlockType blockType)
	{
		if (blockType == BlockType::OBSTACLE_TWO || blockType == BlockType::OBSTACLE_ONE)
		{
			return true;
		}
		return false;
	}

	void GameplayController::onPositionChanged(int position)
	{
		BlockType current_block_type = ServiceLocator::getInstance()->getLevelService()->GetCurrentBlockType(position);

		if (isObstacle(current_block_type))
		{
			ProcessObstacle();
		}
	}

	void GameplayController::destroy()
	{
	}

}