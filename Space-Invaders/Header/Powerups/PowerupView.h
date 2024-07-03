#pragma once
#include <SFML/Graphics.hpp>
#include "UIService/UIElement/ImageView.h"

namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        sf::RenderWindow* game_window;
        sf::Texture powerup_texture;
        sf::Sprite powerup_sprite;

        PowerupController* powerup_controller;
        UI::UIElement::ImageView* powerup_image;

        void createUIElement();
        void initializeImage();
        sf::String getPowerupTexturePath();

        void destroy();

    public:
        PowerupView();
        ~PowerupView();

        void initialize(PowerupController* controller);
        void update();
        void render();
    };
}
