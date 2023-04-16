#ifndef DUNGEONGENERATOR_H_INCLUDED
#define DUNGEONGENERATOR_H_INCLUDED
#include <iostream>
#include "Vector2D.h"
#include "Algorithm.h"
#include "defs.h"
using namespace std;


class AbstractDungeonGenerator
{
protected:

    Vector2D<int> startPosition = Vector2D<int>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
public:
    vector<Vector2D<int>> runProceduralGeneration();
};


class RandomWalkDungeonGenerator: public AbstractDungeonGenerator
{
protected:
    int iterations = 15;
    int walkLength = 30;
    bool startRandomlyEachIteration = false;
    vector<Vector2D<int>> runRandomWalk(Vector2D<int> position)
    {
        Vector2D<int> currPos = position;
        vector<Vector2D<int>> floorPositions;
        for(int i = 0; i < iterations; i++)
        {
            vector<Vector2D<int>> path = SimpleRandomWalk(currPos, walkLength);
            for(int j = 0; j < path.size(); j++) { floorPositions.push_back(path[j]); } // Union
            if(startRandomlyEachIteration)
                currPos = floorPositions[rand() % floorPositions.size()];
        }
        return floorPositions;
    }
public:
    vector<Vector2D<int>> runProceduralGeneration()
    {
        vector<Vector2D<int>> floorPositions = runRandomWalk(startPosition);
        return floorPositions;
    }
};


class CorridorDungeonGenerator: public RandomWalkDungeonGenerator
{
private:
    int corridorLength = 30;
    int corridorCount = 10;
    vector<Vector2D<int>> CreateCorridors()
    {
        vector<Vector2D<int>> floorPositions;
        vector<Vector2D<int>> potentialRoomPositions;
        vector<Vector2D<int>> deadEnds;

        //CreateCorridors
        Vector2D<int> currPos = startPosition;
        for(int i = 0; i < corridorCount; i++)
        {
            auto corridor = RandomWalkCorridor(currPos, corridorLength);
            currPos = corridor[corridor.size()-1];
            potentialRoomPositions.push_back(currPos);
            for(int j = 0; j < corridor.size(); j++)
                floorPositions.push_back(corridor[j]);
        }

        //CreateRooms
        vector<Vector2D<int>>  roomPositions = CreateRooms(potentialRoomPositions);

        //Deadends
        deadEnds = FindAllDeadEnds(floorPositions);
        CreateRoomsAtDeadEnd(deadEnds, roomPositions);

        for(int i = 0; i < roomPositions.size(); i++)
        {
            floorPositions.push_back(roomPositions[i]);
        }

        return floorPositions;
    }
    vector<Vector2D<int>> CreateRooms(vector<Vector2D<int>> potentialRoomPositions)
    {
        vector<Vector2D<int>> roomPositions;
        int roomToCreateCount = (int)(potentialRoomPositions.size() * roomPercent);
        for(int i = 0; i < roomToCreateCount && i < potentialRoomPositions.size(); i++)
        {
            auto roomFloor = runRandomWalk(potentialRoomPositions[i]);
            for(int j = 0; j < roomFloor.size(); j++)
                roomPositions.push_back(roomFloor[j]);
        }
        return roomPositions;
    }

    //Create Rooms at Dead Ends
    void CreateRoomsAtDeadEnd(vector<Vector2D<int>> deadEnds, vector<Vector2D<int>> roomFloors)
    {
        for(int i = 0; i < deadEnds.size(); i++)
        {
            bool contains = false;
            for(int j = 0; j < roomFloors.size(); j++)
            {
                if(roomFloors[j] == deadEnds[i]) {contains = true; break;}
            }
            if(!contains)
            {
                auto rooms = runRandomWalk(deadEnds[i]);
                for(int i = 0; i < rooms.size(); i++)
                    roomFloors.push_back(rooms[i]);
            }
        }
    }

    vector<Vector2D<int>> FindAllDeadEnds(vector<Vector2D<int>> floorPositions)
    {
        vector<Vector2D<int>> deadEnds;
        Direction2D directions;

        for(int i = 0; i < floorPositions.size(); i++)
        {
            int neighboursCount = 0;
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < floorPositions.size(); k++)
                {
                    if(floorPositions[k] == floorPositions[i] + directions.cardinalDirectionsList[j])
                    {
                        neighboursCount++;
                        break;
                    }
                }
            }
            if(neighboursCount <= 1)
                deadEnds.push_back(floorPositions[i]);
        }
        return deadEnds;
    }

public:
    vector<Vector2D<int>> runProceduralGeneration()
    {
        vector<Vector2D<int>> floorPositions = CreateCorridors();
        return floorPositions;
    }
    float roomPercent = 0.6;
};

#endif // DUNGEONGENERATOR_H_INCLUDED
