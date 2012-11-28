#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "maze.h"

#define WIDTH 320
#define HEIGHT 240
#define THICKNESS_SEGMENT 3

void display(maze* pMaze, segments* pSegments);
void SDLPause(void);

#endif // DISPLAY_H_INCLUDED
