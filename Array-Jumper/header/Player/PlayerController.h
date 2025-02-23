#pragma once
#include "../../header/Event/EventService.h"
#include "../../header/Level/BlockType.h"
#include <string>

using namespace Level;
using namespace Event;

namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	enum class MovementDirection;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		PlayerState player_state;
		EventService* event_service;

	public:
		PlayerController();
		~PlayerController();
		void initialize();
		void update();
		void render();
		void destroy();

		void SetPlayerState(PlayerState new_player_state);
		PlayerState GetPlayerState();

		void Move(MovementDirection direction);
		void Jump(MovementDirection direction);
		bool IsPositionInBound(int targetPosition);
		void ReadPlayerInput();
		int GetPlayerPosition();
		BlockType getCurrentBoxValue(int currentPosition);

		void TakeDamage();
	};
}