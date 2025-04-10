#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"
 

using namespace sf;
using namespace UI;

namespace Level
{
	class LevelController;
	class LevelView
	{
	private:
		RenderWindow* game_window;
		UIElement::ImageView* background_image;
		LevelController* level_controller;

		UIElement::ImageView* box_image;

		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;



		BoxDimension box_dimensions;

		const float background_alpha = 110.0f;

		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void deleteImages();


	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initialize();
		void update();
		void render();

		void CalculateBoxDimension();

		UIElement::ImageView* GetBoxOverlayImage(BlockType block_type);

		void DrawBox(Vector2f position);
		void DrawBoxValue(Vector2f position,BlockType box_vale);
		void CalculateBoxWidthAndHeight();
		void CalculateBoxSpacing();
		Vector2f CalculateBoxPositions(int index);
		BoxDimension GetBoxDimensions();
	};
}