#ifndef TILECOMPONENT_H_INCLUDED
#define TILECOMPONENT_H_INCLUDED
#include "ECS.h"
#include "Components.h"
#include "SDL2/SDL.h"

class TileComponent: public Component
{
public:
    TransformComponent* transform;
    SpriteComponent *sprite;

    SDL_Rect tileRectangle;
    int tileID;
    char* path;

    TileComponent(int x, int y, int w, int h, int id)
    {
        tileRectangle.x = x;
        tileRectangle.y = y;
        tileRectangle.w = w;
        tileRectangle.h = h;
    }

};

#endif // TILECOMPONENT_H_INCLUDED
