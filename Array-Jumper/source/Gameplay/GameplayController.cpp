#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

using namespace Global;
using namespace Main;

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

	void GameplayController::ProcessEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->LevelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);

		if (isLastLevel())
		{
			gameOver();
			ServiceLocator::getInstance()->getLevelService()->reset();
			return;
		}

		LoadnextLevel();



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
		if (isEndBlock(current_block_type))
		{
			ProcessEndBlock();
		}
	}

	bool GameplayController::isEndBlock(BlockType value)
	{
		if (value == BlockType::TARGET)
		{
			return true;
		}
		return false;
	}

	void GameplayController::gameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameWon()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);
	}

	void GameplayController::LoadnextLevel()
	{
		ServiceLocator::getInstance()->getLevelService()->LoadNextLevel();
	}

	bool GameplayController::isLastLevel()
	{
		if (ServiceLocator::getInstance()->getLevelService()->isLastLevel())
		{
			return true;
		}

		return false;
	}

	void GameplayController::destroy()
	{
	}

}