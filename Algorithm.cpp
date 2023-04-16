#include "Algorithm.h"

vector<Vector2D<int>> RandomWalkCorridor(Vector2D<int> startPos, int corridorLength)
{
    Direction2D directions;
    vector<Vector2D<int>> corridor;
    Vector2D<int> direction = directions.getRandomCardinalDirection();
    Vector2D<int> currPos = startPos;
    corridor.push_back(currPos);
    for(int i = 0; i < corridorLength; i++)
    {
        currPos += direction;
        corridor.push_back(currPos);
    }
    return corridor;
}

vector<Vector2D<int>> SimpleRandomWalk(Vector2D<int> startPos, int walkLength)
{
    Direction2D directions;
    vector<Vector2D<int>> path;
    path.push_back(startPos);
    Vector2D<int> prevPos = startPos;

    for(int i = 0; i < walkLength; i++)
    {
        Vector2D<int> newPos = prevPos + directions.getRandomCardinalDirection();
        path.push_back(newPos);
        prevPos = newPos;
    }
    return path;
}
