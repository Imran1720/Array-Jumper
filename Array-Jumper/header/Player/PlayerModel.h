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
		const int max_lives = 3;
		int current_lives;

	public:
		void SetPlayerState(PlayerState playerState);
		PlayerState GetPlayerState();
		void initialize();
		void SetPlayerPosition(int new_position);
		int GetCurrentPosition();
		void resetPlayer();
		int GetCurrentLives();
		void DecrementLives();
		void ResetPosition();
	};
}
