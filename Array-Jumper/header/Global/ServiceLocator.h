#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Level/LevelService.h"
#include "../../header/Gameplay/GameplayService.h"

using namespace Event;
using namespace Sound;

namespace Global
{
    
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        EventService* event_service;
        SoundService* sound_service;
        UI::UIService* ui_service;
        Player::PlayerService* player_service;
        Level::LevelService* level_service;
        Gameplay::GameplayService* gameplay_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        EventService* getEventService();
        SoundService* getSoundService();
        UI::UIService* getUIService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();
        Gameplay::GameplayService* getGameplayService();
    };
}