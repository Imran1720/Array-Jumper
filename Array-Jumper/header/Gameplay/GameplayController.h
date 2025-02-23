#pragma once
#include "../../header/Level/BlockType.h"

using namespace Level;

namespace Gameplay
{
	class GameplayController
	{
	private:

		void destroy();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void ProcessObstacle();

		bool isObstacle(BlockType blockType);
		void onPositionChanged(int position);
	};
}