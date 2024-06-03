#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include<iostream>
#include "GameService.h"
using namespace std;

/*
class Player {
private:

    int health = 3 ;
    sf::Vector2f player_position = sf::Vector2f(200.0f,100.0f);
    int player_score = 0 ;
    int movement_speed = 1;

public:
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
    

    int getScore()
    {
        return player_score;
    }
    void setScore(int newScore)
    {
        player_score = newScore;
    }
    sf::Vector2f getPosition()
    {
        return player_position;
    }
    
    int getMoveSpeed()
    {
        return movement_speed;
    }
    void takeDamage() 
    {
    }
    void move(float offsetX)
    {
        player_position.x += offsetX;
    }

    void shootBullets()
    {
    }

   
};
*/
int main()
{
    /*
    //window
    sf::VideoMode videoMode = sf::VideoMode(800,600);
    sf::RenderWindow window(videoMode, "SFML Window");

    //player
    Player player;
    player.player_texture.loadFromFile("assets/textures/player_ship.png");
    player.player_sprite.setTexture(player.player_texture);

    
    // loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.move(-1.0f* player.getMoveSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            player.move(1.0f* player.getMoveSpeed());
        }

        window.clear(sf::Color::Blue);

        player.player_sprite.setPosition(player.getPosition());
        window.draw(player.player_sprite);

        window.display();
    }
    */

    GameService gameService;
    gameService.Ignite();
    while (gameService.isRunning())
    {
        gameService.update();
        gameService.render();
    }
    return 0;
}