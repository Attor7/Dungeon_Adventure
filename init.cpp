#include <SDL2/SDL.h>
#include "init.h"
#include <iostream>


using namespace std;

void initSDL(App& app)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Couldn't initialize SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	app.window = SDL_CreateWindow("The Dungeon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
	    cout << "Failed to open %d x %d window: " << SDL_GetError() << endl;
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
	    cout << "Failed to create renderer: " << SDL_GetError() << endl;
		exit(1);
	}
}
