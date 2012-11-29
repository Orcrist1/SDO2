#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "maze.h"

#define WIDTH 640
#define HEIGHT 480
#define THICKNESS_SEGMENT 1

void display(maze* pMaze, segments* pSegments);
void SDLPause(void);

#endif // DISPLAY_H_INCLUDED
