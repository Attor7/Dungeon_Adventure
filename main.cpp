#include <iostream>
#include <SDL2/SDL.h>
#include "DungeonGenerator.h"
#include "Vector2D.h"
#include "draw.h"
#include "map.h"
#include "Game.h"

Game *game = nullptr;

int main( int argc, char * argv[] )
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    unsigned frameStart;
    int frameTime;

    game = new Game();
    game->init("Dungeon Adventure", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running())
	{
	    //FPS
	    frameStart = SDL_GetTicks();

	    //Game
	    game->handleEvents();
	    game->update();
        game->render();

        //FPS
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

	}

    game->clean();

    return 0;
}

