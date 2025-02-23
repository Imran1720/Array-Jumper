#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Level/LevelController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include <iostream>

using namespace std;
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
		CalculateBoxDimension();
		initializeImages();
	}

	void LevelView::initializeImages()
	{
		background_image->initialize(Config::array_jumper_bg_texture_path, game_window->getSize().x, game_window->getSize().y, Vector2f(0, 0));
		background_image->setImageAlpha(background_alpha);
		
		box_image->initialize(Config::box_texture_path, box_dimensions.box_width, box_dimensions.box_height, Vector2f(0, 0));

		target_overlay_image->initialize(Config::target_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_one_overlay_image->initialize(Config::letter_one_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_two_overlay_image->initialize(Config::letter_two_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		letter_three_overlay_image->initialize(Config::letter_three_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_one_overlay_image->initialize(Config::obstacle_01_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
		obstacle_two_overlay_image->initialize(Config::obstacle_02_texture_path, box_dimensions.box_width, box_dimensions.box_height, sf::Vector2f(0, 0));
	
	}

	void LevelView::createImages()
	{
		background_image = new UIElement::ImageView();
		box_image = new UIElement::ImageView();
		target_overlay_image = new UIElement::ImageView();
		letter_one_overlay_image = new UIElement::ImageView();
		letter_two_overlay_image = new UIElement::ImageView();
		letter_three_overlay_image = new UIElement::ImageView();
		obstacle_one_overlay_image = new UIElement::ImageView();
		obstacle_two_overlay_image = new UIElement::ImageView();
	}

	void LevelView::update()
	{
		updateImages();
	}

	void LevelView::render()
	{
		drawLevel();
	}

	void LevelView::CalculateBoxDimension()
	{
		if (!game_window)
		{
			return;
		}
		CalculateBoxWidthAndHeight();
		CalculateBoxSpacing();
		
	}

	UIElement::ImageView* LevelView::GetBoxOverlayImage(BlockType block_type)
	{
		
			switch (block_type)
			{
			case BlockType::OBSTACLE_TWO:
				return obstacle_two_overlay_image;

			case BlockType::OBSTACLE_ONE:
				return obstacle_one_overlay_image;

			case BlockType::TARGET:
				return target_overlay_image;

			case BlockType::BLOCK_ONE:
				return letter_one_overlay_image;

			case BlockType::BLOCK_TWO:
				return letter_two_overlay_image;

			case BlockType::BLOCK_THREE:
				return letter_three_overlay_image;
			}
			return nullptr;
		
	}

	void LevelView::DrawBox(Vector2f position)
	{
		box_image->setPosition(position);
		box_image->render();
	}

	void LevelView::DrawBoxValue(Vector2f position, BlockType box_value)
	{
		UIElement::ImageView* image = GetBoxOverlayImage(box_value);
		image->setPosition(position);
		image->render();
	}

	void LevelView::CalculateBoxWidthAndHeight()
	{
		float screen_width = game_window->getSize().x;

		int number_of_boxes = LevelData::number_of_boxes;

		int number_of_gaps = number_of_boxes + 1;

		float total_space_for_gap = static_cast<float>(number_of_gaps) * box_dimensions.box_spacing_percentage;

		float total_space = number_of_boxes + total_space_for_gap;

		box_dimensions.box_width = screen_width / (total_space);
		box_dimensions.box_height = box_dimensions.box_width;
	}

	void LevelView::CalculateBoxSpacing()
	{
		box_dimensions.box_spacing = box_dimensions.box_width * box_dimensions.box_spacing_percentage;
	}

	Vector2f LevelView::CalculateBoxPositions(int index)
	{
		float xPosition = box_dimensions.box_spacing + static_cast<float>(index) * (box_dimensions.box_width+box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - box_dimensions.bottom_offset - box_dimensions.box_height;
		return Vector2f(xPosition,yPosition);
	}

	BoxDimension LevelView::GetBoxDimensions()
	{
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		//CalculateBoxDimension();
		return box_dimensions;
	}

	
	void LevelView::drawLevel()
	{
		background_image->render();
		for (int i = 0; i < LevelData::number_of_boxes; i++)
		{
			Vector2f position = CalculateBoxPositions(i);
			DrawBox(position);
			DrawBoxValue(position, level_controller->GetCurretBlockType(i));
		}

	}

	void LevelView::updateImages()
	{
		background_image->update();
		box_image->update();
		target_overlay_image->update();
		letter_one_overlay_image->update();
		letter_two_overlay_image->update();
		letter_three_overlay_image->update();
		obstacle_one_overlay_image->update();
		obstacle_two_overlay_image->update();


	}

	void LevelView::deleteImages()
	{
		delete(background_image);
		delete(box_image);
		delete(target_overlay_image);
		delete(letter_one_overlay_image);
		delete(letter_two_overlay_image);
		delete(letter_three_overlay_image);
		delete(obstacle_one_overlay_image);
		delete(obstacle_two_overlay_image);
	}
}