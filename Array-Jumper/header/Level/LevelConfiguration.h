#pragma once
#include "BlockType.h"
#include "LevelData.h"



namespace Level
{
	class LevelConfiguration
	{
    private:

        BlockType level_1[LevelData::number_of_boxes] =
        {
            BlockType::BLOCK_ONE, 
            BlockType::BLOCK_TWO,
            BlockType::OBSTACLE_ONE, 
            BlockType::BLOCK_TWO,
            BlockType::BLOCK_THREE,
            BlockType::BLOCK_ONE, 
            BlockType::OBSTACLE_TWO,
            BlockType::BLOCK_TWO,
            BlockType::BLOCK_ONE,
            BlockType::TARGET
        };

        BlockType level_2[LevelData::number_of_boxes] =
        {
            BlockType::BLOCK_ONE,
            BlockType::BLOCK_TWO,
            BlockType::OBSTACLE_TWO,
            BlockType::BLOCK_ONE,
            BlockType::BLOCK_TWO,
            BlockType::OBSTACLE_ONE,
            BlockType::BLOCK_THREE,
            BlockType::OBSTACLE_ONE,
            BlockType::BLOCK_ONE,
            BlockType::TARGET
        };

        BlockType level_3[LevelData::number_of_boxes] =
        {
            BlockType::BLOCK_ONE, 
            BlockType::BLOCK_THREE,
            BlockType::OBSTACLE_ONE,
            BlockType::OBSTACLE_TWO,
            BlockType::BLOCK_ONE,
            BlockType::BLOCK_TWO,
            BlockType::OBSTACLE_ONE, 
            BlockType::BLOCK_TWO,
            BlockType::BLOCK_ONE,
            BlockType::TARGET
        };

    public:
        static const int number_of_levels = 3;
        LevelData levels[number_of_levels];
        
        LevelConfiguration()
        {
            for (int i = 0; i < number_of_levels; i++)
            {
                for (int j = 0; j < LevelData::number_of_boxes; j++)
                {
                    levels[i].level_boxes[j] = i==0?level_1[j]:i==1?level_2[j]:level_3[j];
                }
            }
        }

	};
}