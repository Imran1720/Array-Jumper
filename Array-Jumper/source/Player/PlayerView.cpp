#include "../../header/Player/PlayerView.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"

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
		player_width = 1000.0f;
		player_height = 1000.0f;
	}
	void PlayerView::DrawPlayer()
	{
		player_image->render();
	}

	Vector2f PlayerView::CalculatePlayerPosition()
	{
		return Vector2f(0, 0);
	}

	void PlayerView::UpdatePlayerPosition()
	{
		player_image->setPosition(CalculatePlayerPosition());
	}


}