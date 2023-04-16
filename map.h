#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <vector>
#include "Vector2D.h"
#include "DungeonGenerator.h"
#include "WallGenerator.h"

class Map
{
public:
    Map()
    {
        RandomWalkDungeonGenerator randomWalkGenerator;
        CorridorDungeonGenerator randomCorridorGenerator;
        WallGenerator randomWallGenerator;

        floorPositions = randomWalkGenerator.runProceduralGeneration();
        auto corridorFloorPositions = randomCorridorGenerator.runProceduralGeneration();
        for(int i = 0; i < corridorFloorPositions.size(); i++) floorPositions.push_back(corridorFloorPositions[i]);
        wallPositions = randomWallGenerator.createWalls(floorPositions);
    }
    vector<Vector2D<int>> floorPositions;
    vector<Vector2D<int>> wallPositions;

};

#endif // MAP_H_INCLUDED
