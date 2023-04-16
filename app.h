#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include "defs.h"
#include <SDL2/SDL.h>

class App
{
public:
    SDL_Renderer *renderer;
	SDL_Window *window;
	int keyspressed[256];
};

#endif // APP_H_INCLUDED
