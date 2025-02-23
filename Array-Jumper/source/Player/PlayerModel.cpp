#include "../../header/Player/PlayerModel.h"

namespace Player
{
	void PlayerModel::SetPlayerState(PlayerState new_player_state)
	{
		current_state = new_player_state;
	}

	void PlayerModel::initialize()
	{
		resetPlayer();
	}	

	PlayerState PlayerModel::GetPlayerState()
	{
		return current_state;
	}

	void PlayerModel::SetPlayerPosition(int new_player_position)
	{
		current_position = new_player_position;
	}

	int PlayerModel::GetCurrentPosition()
	{
		return current_position;
	}
	void PlayerModel::resetPlayer()
	{
		ResetPosition();
		current_lives = max_lives;
		SetPlayerState(PlayerState::Alive);
	}
	int PlayerModel::GetCurrentLives()
	{
		return current_lives;
	}

	void PlayerModel::DecrementLives()
	{
		current_lives--;
	}

	void PlayerModel::ResetPosition()
	{
		current_position = 0;
	}


}