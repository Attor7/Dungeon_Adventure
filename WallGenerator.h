#ifndef WALLGENERATOR_H_INCLUDED
#define WALLGENERATOR_H_INCLUDED
#include <vector>
#include "Vector2D.h"
#include "Algorithm.h"

class WallGenerator
{
public:
    vector<Vector2D<int>> createWalls(vector<Vector2D<int>> floorPositions)
    {
        Direction2D directions;
        vector<Vector2D<int>> basicWallPositions = FindWallsInDirections(floorPositions, directions.cardinalDirectionsList);
        return basicWallPositions;
    }
private:
    vector<Vector2D<int>> FindWallsInDirections(vector<Vector2D<int>> floorPositions, Vector2D<int> directionList[4])
    {
        vector<Vector2D<int>> wallPositions;
        for(int i = 0; i < floorPositions.size(); i++)
        {
            for(int j = 0; j < 4; j++)
            {
                bool contains = false;
                Vector2D<int> neighbourPos = floorPositions[i] + directionList[j];
                for(int k = 0; k < floorPositions.size(); k++)
                {
                    if(floorPositions[k] == neighbourPos) contains = true;
                }
                if(!contains) wallPositions.push_back(neighbourPos);
            }

        }
        return wallPositions;
    }
};

#endif // WALLGENERATOR_H_INCLUDED
