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
	BlockType LevelModel::GetCurretBoxValue(int current_position)
	{
		return current_level_data.level_boxes[current_position];
	}
}