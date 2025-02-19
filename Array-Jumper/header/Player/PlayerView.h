#pragma once
#include "SFML/Graphics.hpp"
#include "../../header/UI/UIElement/ImageView.h"

using namespace sf;
using namespace UI;

namespace Player
{
	class PlayerView
	{
	private:
		RenderWindow* game_window;
		UIElement::ImageView* player_image;

		float player_width;
		float player_height;

		void InitializePlayerImage();
		void LoadPlayer();
		void DrawPlayer();
		void CalculatePlayerDimension();
		Vector2f CalculatePlayerPosition();
		void UpdatePlayerPosition();

	public:

		PlayerView();
		~PlayerView();
		void initialize();
		void render();
		void update();
	};
}