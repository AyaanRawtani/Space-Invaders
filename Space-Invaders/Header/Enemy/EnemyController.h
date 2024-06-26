#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;
    enum class EnemyType;

    class EnemyController
    {
    protected:

        EnemyView* enemy_view;
        EnemyModel* enemy_model;
        EnemyType* enemy_type;

        virtual void move() = 0;
        void moveLeft();
        void moveRight();
        void moveDown();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        EnemyType getEnemyType();
        void setEnemyType(EnemyType type);
        //void getEnemyType();
        sf::Vector2f getEnemyPosition();
    };
}
