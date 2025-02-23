#pragma once

namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		PlayerState player_state;

	public:
		PlayerController();
		~PlayerController();
		void initialize();
		void update();
		void render();
		void destroy();

		void SetPlayerState(PlayerState new_player_state);
		PlayerState GetPlayerState();

		int GetPlayerPosition();
	};
}