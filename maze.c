#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "myRandom.h"

maze* createMaze(const unsigned int height,const unsigned int width)
{
    maze* pMaze = malloc(sizeof(maze));

    if(pMaze != NULL)
    {
        pMaze->array = malloc(height * sizeof(unsigned int*));
        if(pMaze->array != NULL)
        {
            for(unsigned int i = 0; i < height; i++)
                pMaze->array[i] = calloc(width, sizeof(unsigned int));

            unsigned int e = 0;
            for(unsigned int i = 0; i < height; i++)
            {
                for(unsigned int j = 0; j < width;  j++)
                {
                    pMaze->array[i][j] = e;
                    e++;
                }
            }
            pMaze->height = height;
            pMaze->width  = width;
        }
    }

    return pMaze;
}


bool destroyMaze(maze* pMaze)
{
    bool state = false;

    if(pMaze != NULL)
    {
        if(pMaze->array != NULL)
        {
            for(int i = 0; i < pMaze->height; i++)
                free(pMaze->array[i]);

            free(pMaze->array);
            pMaze->array = NULL;

            free(pMaze);
            pMaze = NULL;

            state = true;
        }
    }

    return state;
}

bool openDoor(maze* pMaze, segments* pSegments, unsigned int index)
{
    bool state = false;
    if(pMaze != NULL && pSegments != NULL)
    {
        if(*pSegments->arraySegment[index].b != *pSegments->arraySegment[index].a)
        {
            for(int i = 0; i < pMaze->height; i++)
            {
                for(int j = 0; j < pMaze->width; j++)
                {
                    if(pSegments->arraySegment[index].b == &pMaze->array[i][j])
                        j++;

                    if(*pSegments->arraySegment[index].b == pMaze->array[i][j])
                    {
                            printf("modifie la valeur %i en %i\n",pMaze->array[i][j], *pSegments->arraySegment[index].a);
                            pMaze->array[i][j] = *pSegments->arraySegment[index].a;
                            state = true;
                    }
                }
            }
             printf("modifie la valeur %i en %i\n", *pSegments->arraySegment[index].b, *pSegments->arraySegment[index].a);
            *pSegments->arraySegment[index].b = *pSegments->arraySegment[index].a;
            pSegments->arraySegment[index].visited = true;
        }
    }
    return state;
}

void fillMaze(maze* pMaze)
{
}
