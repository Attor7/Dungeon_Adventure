#ifndef SPRITECOMPONENT_H_INCLUDED
#define SPRITECOMPONENT_H_INCLUDED
#include "Components.h"
#include "draw.h"
#include <SDL2/SDL.h>
#include "Animation.h"
#include <map>

class SpriteComponent: public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;


    bool animatable = false;
    int frameCount = 1;
    int speed = 100;

public:
    int animationIndex = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    std::map<const char*, Animation> animations;

    SpriteComponent(const char* path, map<const char*, Animation> animations)
    {
        animatable = true;

        this->animations = animations;

        setTex(path);
    }
    SpriteComponent(const char* path)
    {
        animatable = false;
        setTex(path);
    }
    ~SpriteComponent() {SDL_DestroyTexture(texture);}
    void setTex(const char* path)
    {
        texture = Visualizer::loadTexture(path);
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;

    }

    void update() override
    {
        if(animatable)
        {
            //animation
            srcRect.x = srcRect.w * (int)(SDL_GetTicks() / speed % frameCount);
        }

        //For multirow animation
        srcRect.y = animationIndex * transform->height;

        //move sprite with transform
        destRect.x = (int)transform->position.x - Game::Camera.x;
        destRect.y = (int)transform->position.y - Game::Camera.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;

    }

    void draw() override
    {
        Visualizer::draw(texture, &srcRect, &destRect, flip);
    }

    void Play(const char* animationName)
    {
        frameCount = animations[animationName].frameCount;
        animationIndex = animations[animationName].index;
        speed = animations[animationName].speed;
        setTex(animations[animationName].path.c_str());
    }


};

#endif // SPRITECOMPONENT_H_INCLUDED
