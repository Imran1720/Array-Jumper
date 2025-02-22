#pragma once
#include "LevelData.h"

namespace Level
{
	struct BoxDimension
	{
		float box_width;
		float box_height;
		float box_spacing;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.0f;

	};

	class LevelModel
	{
	private:
		LevelData current_level_data;
	public:
		LevelModel();
		~LevelModel();
		void initialize();

		BlockType GetCurretBlockType(int current_position);
	};
}