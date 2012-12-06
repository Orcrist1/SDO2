#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "maze.h"

#define WIDTH 640
#define HEIGHT 480
#define THICKNESS_SEGMENT 1

void display(maze* pMaze, segments* pSegments);
void SDLPause(void);

void displayV(maze* pMaze, segments* pSegments);
void displayH(maze* pMaze, segments* pSegments);
#endif // DISPLAY_H_INCLUDED
