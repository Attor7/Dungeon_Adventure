#include "Game.h"
#include "GameObject.h"
#include "ECS.h"
#include "Vector2D.h"
#include "Components.h"
#include "Collision.h"
#include <iostream>

using namespace std;

Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Window* Game::window = nullptr;
SDL_Event Game::event;
Map Game::gameMap;
vector<ColliderComponent*> colliders;
vector<TransformComponent*> tiles;

SDL_Rect Game::Camera = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT};

Entity* player;
Vector2D<float> playerPos(0.0, 0.0);
Vector2D<float> playerVel(0.0, 0.0);
int playerSpeed;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int windowFlags;

	if(fullscreen) windowFlags = SDL_WINDOW_FULLSCREEN;
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
	    isRunning = false;
		cout << "Couldn't initialize SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, windowFlags);

	if (!window)
	{
	    cout << "Failed to open %d x %d window: " << SDL_GetError() << endl;
		exit(1);
	}

	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
	    cout << "Failed to create renderer: " << SDL_GetError() << endl;
		exit(1);
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //map
    generateMap();

    //player
    generatePlayer();
    manager.refresh();
    manager.update();


    while(Collision::objCollision(player->getComponent<ColliderComponent>().collider, colliders))
    {
        std::cout << "x" << std::endl;
        generateMap();
    }


	isRunning = true;
}

void Game::generatePlayer()
{
    player = &manager.addEntity();
	player->addComponent<TransformComponent>(SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-50, 32, 32, 6);
	player->addComponent<SpriteComponent>("assets/Player/HumanAll.PNG", Animation::HumanAnimations);
    player->addComponent<KeyboardController>();
    player->addComponent<ColliderComponent>("player");
}

void Game::generateMap()
{
    gameMap = Map();

    for(auto& pos: gameMap.floorPositions)
    {
        auto& floor(manager.addEntity());
        floor.addComponent<TransformComponent>(pos.x, pos.y, FLOOR_WIDHT, FLOOR_HEIGHT, 1);
        floor.addComponent<SpriteComponent>("assets/tiles/floor_2.PNG");
        tiles.push_back(&floor.getComponent<TransformComponent>());
    }
    for(auto& pos: gameMap.wallPositions)
    {
        auto& wall(manager.addEntity());
        wall.addComponent<TransformComponent>(pos.x, pos.y, FLOOR_WIDHT, FLOOR_HEIGHT, 1);
        wall.addComponent<SpriteComponent>("assets/tiles/wall_stone.PNG");
        wall.addComponent<ColliderComponent>("wall");
        colliders.push_back(&wall.getComponent<ColliderComponent>());
        tiles.push_back(&wall.getComponent<TransformComponent>());
    }
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    playerPos = player->getComponent<TransformComponent>().position;
    playerVel = player->getComponent<TransformComponent>().velocity;
    playerSpeed = player->getComponent<TransformComponent>().speed;

    manager.refresh();
    manager.update();

    Camera.x = player->getComponent<TransformComponent>().position.x - SCREEN_WIDTH / 2;
    Camera.y = player->getComponent<TransformComponent>().position.y - SCREEN_HEIGHT / 2;

    /*
    if(Camera.x < 0)
        Camera.x = 0;
    if(Camera.y < 0)
        Camera.y = 0;
    if(Camera.x > Camera.w)
        Camera.x = Camera.w;
    if(Camera.y > Camera.h)
        Camera.y = Camera.h;
    */
    if(Collision::objCollision(player->getComponent<ColliderComponent>().collider, colliders))
    {
        player->getComponent<TransformComponent>().position = playerPos;
    }


}

void Game::render()
{
    SDL_RenderClear(renderer);
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_QUIT;
}


