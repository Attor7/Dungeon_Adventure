#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SDL2/SDL.h>
#include "map.h"
#include <vector>
#include "ECS.h"

class Game
{
private:
    bool isRunning;
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    void generateMap();
    void generatePlayer();

    bool running() {return isRunning;}

    static SDL_Window *window;
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static Map gameMap;
    static SDL_Rect Camera;
};

#endif // GAME_H_INCLUDED
