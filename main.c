#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "myRandom.h"
#include "display.h"

#define N 2

void f(maze *pMaze)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%02d ", pMaze->array[i][j]);
        }
        printf("\n");
    }
       printf("\n");
}

int main(void)
{
    maze* pMaze = createMaze(N, N);
    segments* pSegments = createSegments(pMaze);
    randomNumber* pRandomNumber = createNumberRandom(0, pSegments->size);

//getRandomNumber(pRandomNumber)
    for(unsigned int i = 0; i < pSegments->size; i++)
    {
        openDoor(pMaze, pSegments, getRandomNumber(pRandomNumber));
        f(pMaze);
    }

    display(pMaze, pSegments);

    printf("\n1 -> supprimer le segment\n"
           "0 > ajouter le segment\n");
    for(unsigned int i = 0; i < pSegments->size; i++)
    {
        printf("segments[%d] : %d\n",i ,pSegments->arraySegment[i].visited);
    }

    destroySegments(pSegments);
    destroyMaze(pMaze);
    destroyNumberRandom(pRandomNumber);

    return 0;
}
