#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <map>
#include <string>
#include <SDL2/SDL.h>
#include "draw.h"

class Animation
{
public:
    int index;
    int frameCount;
    int speed;
    std::string path;
    Animation() = default;
    Animation(int index, int frameCount, int speed, const char* path)
    {
        this->index = index;
        this->frameCount = frameCount;
        this->speed = speed;
        this->path = path;
    }

    static map<const char*, Animation> HumanAnimations;
};

map<const char*, Animation> Animation::HumanAnimations
{
    {"Idle", Animation(0, 16, 100, "assets/Player/Idle.PNG")},
    {"Walk", Animation(0, 4, 100, "assets/Player/Walk.PNG")}
};



#endif // ANIMATION_H_INCLUDED
