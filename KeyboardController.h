#ifndef KEYBOARDCONTROLLER_H_INCLUDED
#define KEYBOARDCONTROLLER_H_INCLUDED
#include "Components.h"

class KeyboardController: public Component
{
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
    }
    void update() override
    {
        if(Game::event.type == SDL_KEYDOWN)
        {
            switch(Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = -1;
                sprite->Play("Walk");
                break;
            case SDLK_a:
                transform->velocity.x = -1;
                sprite->Play("Walk");
                break;
            case SDLK_s:
                transform->velocity.y = 1;
                sprite->Play("Walk");
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                sprite->Play("Walk");
                if(transform->velocity.x >= 0) sprite->flip = SDL_FLIP_NONE;
                break;
            }
            if(transform->velocity.x < 0) sprite->flip = SDL_FLIP_HORIZONTAL; //FLIP
        }
        if(Game::event.type == SDL_KEYUP)
        {
            switch(Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                break;
            case SDLK_a:
                transform->velocity.x = 0;

                break;
            case SDLK_s:
                transform->velocity.y = 0;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                break;
            }
            if(transform->velocity.x == 0 && transform->velocity.y == 0) sprite->Play("Idle"); //STOP WALK


        }
    }


};

#endif // KEYBOARDCONTROLLER_H_INCLUDED
