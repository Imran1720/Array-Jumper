#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/UI/UIElement/TextView.h"
#include <SFML/Graphics.hpp>

using namespace Global;
using namespace sf;
using namespace UI;

namespace Gameplay
{
	
	GameplayUIController::GameplayUIController()
	{
		life_count_text = new UIElement::TextView();
		level_count_text = new UIElement::TextView();
	}
	GameplayUIController::~GameplayUIController()
	{
		destroy();
	}
	void GameplayUIController::initialize()
	{
		initializeLifeCountText();
		initializeLevelCountText();
	}
	void GameplayUIController::update()
	{
		updateLifeCountText();
		updateLevelCountText();
	}
	void GameplayUIController::render()
	{
		life_count_text->render();
		level_count_text->render();
	}

	void GameplayUIController::destroy()
	{
		delete(life_count_text);
		delete(level_count_text);
	}

	void GameplayUIController::initializeLifeCountText()
	{
		float window_width = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;

		float xPosition = window_width - right_offset;
		float yPosition = top_offset;

		life_count_text->initialize("0", Vector2f(xPosition, yPosition), UIElement::FontType::BUBBLE_BOBBLE, font_size, Color::White);

	}
	void GameplayUIController::initializeLevelCountText()
	{
		float window_width = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;

		float xPosition = left_offset;
		float yPosition = top_offset;
		level_count_text->initialize("0", Vector2f(xPosition, yPosition), UIElement::FontType::BUBBLE_BOBBLE, font_size, Color::White);
	}
	void GameplayUIController::updateLifeCountText()
	{
		int life_count = ServiceLocator::getInstance()->getPlayerService()->GetCurrentLives();

		std::string life_count_string = "LIFE : " + std::to_string(life_count);

		life_count_text->setText(life_count_string);
		life_count_text->update();
	}
	void GameplayUIController::updateLevelCountText()
	{
		int level_count = ServiceLocator::getInstance()->getLevelService()->GetCurrentLevelIndex();
		sf::String level_count_string = "LEVEL : " + std::to_string(level_count);
		level_count_text->setText(level_count_string);
		level_count_text->update();
	}
}