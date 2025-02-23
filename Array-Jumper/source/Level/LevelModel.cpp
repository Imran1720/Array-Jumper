#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel()
	{
	}
	LevelModel::~LevelModel()
	{
	}
	void LevelModel::initialize()
	{

	}
	int LevelModel::GetCurrentLevelIndex()
	{
		return current_level_index+1;
	}
	bool LevelModel::isLastLevel()
	{
		if (current_level_index == LevelConfiguration::number_of_levels - 1)
		{
			return true;
		}
		return false;
	}
	void LevelModel::LoadNextLevel()
	{
			current_level_index++;
	}
	void LevelModel::reset()
	{
		current_level_index = 0;
	}
	BlockType LevelModel::GetCurretBoxValue(int current_position)
	{
		return level_configuration.levels[current_level_index].level_boxes[current_position];
	}
}