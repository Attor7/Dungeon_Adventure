#ifndef COLLIDER_H_INCLUDED
#define COLLIDER_H_INCLUDED
#include <string>
#include <SDL2/SDL.h>

class ColliderComponent: public Component
{
private:
    bool corrected = true;
public:
    SDL_Rect collider;
    std::string tag;
    TransformComponent* transform;

    ColliderComponent(std::string tag = "notag")
    {
        this->tag = tag;
    }
    void init() override
    {
        if(!entity->hasComponent<TransformComponent>())
        {
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }
    void update() override
    {
        collider.x = (int)(transform->position.x);
        collider.y = (int)(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;
        if(tag == "player")
        {
            collider.w = transform->width;
            collider.h = transform->height;
            float x = transform->width * transform->scale / 2;
            float y = transform->height * transform->scale / 2;
            collider.x += x - collider.w/2;
            collider.y += y - collider.h/2;
        }

    }

};

#endif // COLLIDER_H_INCLUDED
