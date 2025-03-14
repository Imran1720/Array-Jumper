#pragma once
#include "../../header/Level/BlockType.h"
#include "../../header/Level/LevelModel.h"

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelView* level_view;
		LevelModel* level_model;

		void destroy();

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();
		BlockType GetCurretBlockType(int current_position);

		BoxDimension GetBoxDimensions();

		bool isLastLevel();
		void LoadNextLevel();
		void reset();
		int GetCurrentLevelIndex();

	};
}