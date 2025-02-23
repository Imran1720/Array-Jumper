#pragma once
#include "LevelConfiguration.h"

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
		LevelConfiguration level_configuration;
		int current_level_index=0;

	public:
		LevelModel();
		~LevelModel();
		void initialize();
		BlockType GetCurretBoxValue(int current_position);

		int GetCurrentLevelIndex();
		bool isLastLevel();
		void LoadNextLevel();
		void reset();
	};
}