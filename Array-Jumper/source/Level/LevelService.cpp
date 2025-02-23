#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	BoxDimension LevelService::GetBoxDimensions()
	{
		return level_controller->GetBoxDimensions();
	}

	BlockType LevelService::GetCurrentBlockType(int currentPosition)
	{
		return level_controller->GetCurretBlockType(currentPosition);
	}

	int LevelService::GetCurrentLevelIndex()
	{
		return level_controller->GetCurrentLevelIndex();
	}

	bool LevelService::isLastLevel()
	{
		return level_controller->isLastLevel();
	}

	void LevelService::LoadNextLevel()
	{
		level_controller->LoadNextLevel();
	}

	void LevelService::reset()
	{
		level_controller->reset();
	}


	void LevelService::destroy()
	{
		delete(level_controller);
	}
}