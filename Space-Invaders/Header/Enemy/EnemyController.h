#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    class EnemyController
    {
    protected:

        float vertical_movement_speed = 30.f;
        float horizontal_movement_speed = 200.f;

        float rate_of_fire = 2.5f;
        float elapsed_fire_duration = 0.f;

        EnemyView* enemy_view;
        EnemyModel* enemy_model;
        EnemyType* enemy_type;

        void updateFireTimer();
        void processBulletFire();
        virtual void fireBullet() = 0;

        virtual void move() = 0;
        //void moveLeft();
        //void moveRight();
        //void moveDown();

        sf::Vector2f getRandomInitialPosition();
        void handleOutOfBounds();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        EnemyType getEnemyType();
        EnemyState getEnemyState();
        //void setEnemyType(EnemyType type);
        //void getEnemyType();
        sf::Vector2f getEnemyPosition();
    };
}
