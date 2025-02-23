#pragma once
#include "../../header//UI/UIElement/TextView.h"

using namespace UI;

namespace Gameplay
{
	class GameplayUIController
	{
	private :
		float font_size = 55;

		const float top_offset = 100.f;
		const float left_offset = 100.f;
		const float right_offset = 250.f;

		UIElement::TextView* life_count_text;

		void destroy();
		void initializeLifeCountText();
		void updateLifeCountText();

	public:
		GameplayUIController();
		~GameplayUIController();

		void initialize();
		void update();
		void render();
	};
}