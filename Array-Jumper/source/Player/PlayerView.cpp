#include "../../header/Player/PlayerView.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include <iostream>

using namespace std;

using namespace UI;
using namespace Global;
namespace Player
{
	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		game_window = nullptr;
		player_image = new UIElement::ImageView();
	}
	PlayerView::~PlayerView()
	{
	}

	void PlayerView::update()
	{
		switch (player_controller->GetPlayerState())
		{
		case PlayerState::Alive:
		UpdatePlayerPosition();
			break;
		}
	}

	void PlayerView::render()
	{
		switch (player_controller->GetPlayerState())
		{
		case PlayerState::Alive :
			DrawPlayer();
			break;
		}
	}


	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}
	

	void PlayerView::LoadPlayer()
	{
		CalculatePlayerDimension();
		InitializePlayerImage();
	}

	void PlayerView::InitializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path, player_width, player_height, Vector2f(0, 0));
	}

	void PlayerView::CalculatePlayerDimension()
	{
		current_box_dimension = ServiceLocator::getInstance()->getLevelService()->GetBoxDimensions();
		cout<< current_box_dimension.box_height<<endl;
		player_width = current_box_dimension.box_width;
		player_height = current_box_dimension.box_height;
	}
	void PlayerView::DrawPlayer()
	{
		player_image->render();
	}

	Vector2f PlayerView::CalculatePlayerPosition()
	{
		float xPosition = current_box_dimension.box_spacing + static_cast<float>(player_controller->GetPlayerPosition()) * (current_box_dimension.box_width + current_box_dimension.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y)-current_box_dimension.bottom_offset-current_box_dimension.box_height -player_height;
		return Vector2f(xPosition, yPosition);
	}

	void PlayerView::UpdatePlayerPosition()
	{
		player_image->setPosition(CalculatePlayerPosition());
	}


}