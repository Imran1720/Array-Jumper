#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{
	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		destroy();
	}

	void PlayerController::initialize()
	{
		player_view->initialize();
		player_model->initialize();
	}

	void PlayerController::update()
	{
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::SetPlayerState(PlayerState new_player_state)
	{
		player_model->SetPlayerState(new_player_state);
	}

	PlayerState PlayerController::GetPlayerState()
	{
		return player_model->GetPlayerState();
	}

	int PlayerController::GetPlayerPosition()
	{
		return player_model->GetCurrentPosition();
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

}
