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

maze* createMaze(const unsigned int height, const unsigned int width);
bool destroyMaze(maze* pMaze);
bool openDoor(maze* pMaze, segments* pSegments, unsigned int index);
void fillMaze(maze* pMaze);

#endif // MAZE_H_INCLUDED
