#pragma once
#include "SFML/Graphics.hpp"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"

using namespace sf;
using namespace UI;
using namespace Level;

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		RenderWindow* game_window;
		UIElement::ImageView* player_image;
		PlayerController* player_controller;
		BoxDimension current_box_dimension;

		float player_width;
		float player_height;

		void InitializePlayerImage();
		void LoadPlayer();
		void DrawPlayer();
		void CalculatePlayerDimension();
		Vector2f CalculatePlayerPosition();
		void UpdatePlayerPosition();

	public:

		PlayerView(PlayerController* controller);
		~PlayerView();
		void initialize();
		void render();
		void update();
	};
}