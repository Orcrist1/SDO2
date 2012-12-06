#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <stdbool.h>

typedef struct maze_t maze;
#include "segment.h"

struct maze_t
{
    unsigned int** array;
    int height;
    int width;
};

maze* createMaze(unsigned int height, unsigned int width, int startValue);
bool destroyMaze(maze* pMaze);
bool openDoor(maze* pMaze, segments* pSegments, int index);

#endif // MAZE_H_INCLUDED
