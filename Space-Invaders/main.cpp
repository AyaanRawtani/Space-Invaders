#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include<iostream>
#include "Main/GameService.h"
using namespace std;
using namespace Main;


int main()
{
    GameService* game_service = new GameService;
    game_service->ignite();
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }
    return 0;
}