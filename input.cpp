#include "input.h"
#include <SDL2/SDL.h>

void keyDown(SDL_KeyboardEvent e, App& app)
{
    app.keyspressed[e.keysym.scancode] = 1;
}

void keyUp(SDL_KeyboardEvent e, App& app)
{
    app.keyspressed[e.keysym.scancode] = 0;
}

void getInput(App& app)
{
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            keyDown(e.key, app);
            break;
        case SDL_KEYUP:
            keyUp(e.key, app);
            break;
        default:
            break;
        }

    }

}


