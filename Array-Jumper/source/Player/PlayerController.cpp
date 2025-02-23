#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/MovementDirection.h"
#include "../../header/Global/ServiceLocator.h"

using namespace Global;

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
		event_service = ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::update()
	{
		player_view->update();
		ReadPlayerInput();
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

	void PlayerController::Move(MovementDirection direction)
	{
		int steps, target_position;

		switch (direction)
		{
		case MovementDirection::FORWARD :
			steps = 1;
			break;
		case MovementDirection::BACKWARD :
			steps = -1;
			break;
		default:steps = 0;
			break;
		}

		target_position = player_model->GetCurrentPosition() + steps;

		if (!IsPositionInBound(target_position))
		{
			return;
		}

		player_model->SetPlayerPosition(target_position);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
		
	}

	bool PlayerController::IsPositionInBound(int targetPosition)
	{
		if (targetPosition > 0 && targetPosition < LevelData::number_of_boxes)
		{
			return true;
		}
		return false;
	}

	void PlayerController::ReadPlayerInput()
	{
		if (event_service->pressedAKey() || event_service->pressedLeftArrowKey())
		{
			Move(MovementDirection::BACKWARD);
		}
		if (event_service->pressedDKey() || event_service->pressedRightArrowKey())
		{
			Move(MovementDirection::FORWARD);
		}
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
