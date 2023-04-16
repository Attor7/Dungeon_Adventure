#include "GameObject.h"
#include "draw.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
    objTexture = Visualizer::loadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

void GameObject::Update()
{
    xpos++;
    ypos++;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 6;
    destRect.h = srcRect.h * 6;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
