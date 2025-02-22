#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_model = new LevelModel();
		level_view = new LevelView(this);
	}

	LevelController::~LevelController()
	{
		destroy();
	}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BlockType LevelController::GetCurretBlockType(int current_position)
	{
		//return level_model->GetCurretBlockType(current_position);
		return BlockType::BLOCK_ONE;
	}

	void LevelController::destroy()
	{
		delete(level_model);
		delete(level_view);
	}
}