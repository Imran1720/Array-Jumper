#pragma once
#include "../../header/Level/BlockType.h"
namespace Level
{
	struct LevelData
	{
		static const int number_of_boxes = 10;
		BlockType level_boxes[number_of_boxes] = {
			BlockType::BLOCK_ONE,
			BlockType::BLOCK_TWO,
			BlockType::OBSTACLE_ONE,
			BlockType::BLOCK_TWO,
			BlockType::BLOCK_THREE,
			BlockType::OBSTACLE_TWO,
			BlockType::BLOCK_ONE,
			BlockType::BLOCK_TWO,
			BlockType::OBSTACLE_ONE,
			BlockType::TARGET,
		};
	};
}