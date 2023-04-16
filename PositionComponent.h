#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED
#include "Vector2D.h"

class TransformComponent: public Component
{
public:
    Vector2D<float> position{0, 0};
    Vector2D<float> velocity{0, 0};
    int speed = 10;

    int height = 32;
    int width = 32;
    int scale = 1;

    TransformComponent(int scale)
    {
        this->scale = scale;
    }
    TransformComponent(float x = 0.0, float y = 0.0)
    {
        position.x = x;
        position.y = y;
    }
    TransformComponent(float x, float y, float height, float width, int scale)
    {
        position.x = x;
        position.y = y;
        this->width = width;
        this->height = height;
        this->scale = scale;
    }

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }
    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};


#endif // POSITIONCOMPONENT_H_INCLUDED
