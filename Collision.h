#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL2/SDL.h>
#include "Collider.h"
#include "draw.h"

class Collision
{
public:
    static bool collided(const SDL_Rect A, const SDL_Rect B)
    {
        if (A.x + A.w >= B.x &&
           B.x + B.w >= A.x &&
           A.y + A.h >= B.y &&
           B.y + B.h >= A.y) { return true; }
        return false;
    }
    static bool objCollision(const SDL_Rect playerRect, vector<ColliderComponent*> colliders)
    {
        for(int i = 0; i < colliders.size(); i++)
        {
            if(collided(playerRect, colliders[i]->collider)) return true;

        }
        return false;
    }
};

#endif // COLLISION_H_INCLUDED
