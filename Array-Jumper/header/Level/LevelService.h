#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelData current_level_data;

		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

	};
}