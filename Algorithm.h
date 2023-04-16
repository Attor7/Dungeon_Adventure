#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED
#include <vector>
#include <iostream>
#include "defs.h"
#include "Vector2D.h"

using namespace std;

class Direction2D
{
public:
    Vector2D<int> cardinalDirectionsList[4] =
    {
        Vector2D<int>(0,FLOOR_HEIGHT), //UP
        Vector2D<int>(FLOOR_WIDHT,0), //RIGHT
        Vector2D<int>(0,-FLOOR_HEIGHT), //DOWN
        Vector2D<int>(-FLOOR_WIDHT,0) // LEFT
    };
    Vector2D<int> getRandomCardinalDirection()
    {
        return cardinalDirectionsList[rand() % 4];
    }

};

vector<Vector2D<int>> RandomWalkCorridor(Vector2D<int> startPos, int corridorLength);
vector<Vector2D<int>> SimpleRandomWalk(Vector2D<int> startPos, int walkLength);

#endif // ALGORITHM_H_INCLUDED
