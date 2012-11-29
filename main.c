#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "myRandom.h"
#include "display.h"

#define N 200

int main(void)
{
    maze* pMaze = createMaze(N, N);
    segments* pSegments = createSegments(pMaze);
    randomNumber* pRandomNumber = createNumberRandom(0, pSegments->size);

    for(unsigned int i = 0; i < pSegments->size; i++)
        openDoor(pMaze, pSegments, getRandomNumber(pRandomNumber));

    display(pMaze, pSegments);

    destroySegments(pSegments);
    destroyMaze(pMaze);
    destroyNumberRandom(pRandomNumber);

    return 0;
}
