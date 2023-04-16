#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED
#include "Vector2D.h"
#include "Game.h"
#include <vector>
using namespace std;

class Visualizer
{
public:

    static void prepareScene()
    {
        SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
        SDL_RenderClear(Game::renderer);
    }
    static void presentScene();
    static SDL_Texture *loadTexture(const char* filename);
    static void drawTiles(vector<Vector2D<int>> positions, int w, int h, const char* img);
    static void draw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect, SDL_RendererFlip flip);


};

#endif // DRAW_H_INCLUDED

