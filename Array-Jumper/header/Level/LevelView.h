#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

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

	};
}