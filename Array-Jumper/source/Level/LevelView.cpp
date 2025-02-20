#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"

using namespace Global;

namespace Level
{
	LevelView::LevelView(LevelController* controller)
	{
		game_window = nullptr;
		level_controller = controller;
		createImages();
	}
	LevelView::~LevelView()
	{
		deleteImages();
	}

	void LevelView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImages();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
	}

	void LevelView::createImages()
	{
		background_image = new UIElement::ImageView();
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::drawLevel()
	{
		background_image->render();
	}

	void LevelView::updateImages()
	{
		background_image->update();
	}

	void LevelView::deleteImages()
	{
		delete(background_image);
	}
}