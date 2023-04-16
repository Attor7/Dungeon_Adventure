#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector2D.h"
#include "draw.h"

SDL_Texture *Visualizer::loadTexture(const char* filename)
{
        SDL_Texture *texture;
        SDL_Surface *surface;

        surface = IMG_Load(filename);

        //SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xFF, 0, 0xFF));

        texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
        SDL_FreeSurface(surface);

        return texture;
}

void Visualizer::drawTiles(vector<Vector2D<int>> positions, int w, int h, const char* img)
{
    std::cout << positions.size() << std::endl;
    SDL_Rect destRect;
    destRect.w = w;
    destRect.h = h;
    SDL_Texture* texture = loadTexture(img);
    for(int i = 0; i < positions.size(); i++)
    {
        destRect.x = positions[i].x;
        destRect.y = positions[i].y;
        draw(texture, nullptr, &destRect, SDL_FLIP_NONE);
    }
}

void Visualizer::presentScene()
{
    SDL_RenderPresent(Game::renderer);
}

void Visualizer::draw(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* destRect, SDL_RendererFlip flip)
{

    SDL_RenderCopyEx(Game::renderer, texture, srcRect, destRect, NULL, NULL, flip);
}
