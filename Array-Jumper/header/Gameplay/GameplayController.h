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
		void ProcessEndBlock();

		bool isObstacle(BlockType blockType);
		void onPositionChanged(int position);
		bool isEndBlock(BlockType value);
		void gameOver();
		void onDeath();
	};
}