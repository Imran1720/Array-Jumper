#pragma once

namespace Player
{
	enum class PlayerState
	{
		Alive,
		Dead
	};

	class PlayerModel
	{
	private:
		PlayerState current_state;
		int current_position;

	public:
		void SetPlayerState(PlayerState playerState);
		PlayerState GetPlayerState();

		void SetPlayerPosition(int new_position);
		int GetCurrentPosition();

	};
}
