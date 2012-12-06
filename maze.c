#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "myRandom.h"

maze* createMaze(unsigned int height, unsigned int width, int startValue)
{
    maze* pMaze = malloc(sizeof(maze));

    if(pMaze != NULL)
    {
        pMaze->array = malloc(height * sizeof(int*));
        if(pMaze->array != NULL)
        {
            for(unsigned int i = 0; i < height; i++)
            {
                pMaze->array[i] = calloc(width, sizeof(int));
                if(pMaze->array[i] == NULL)
                {
                    for(int j = i; j >= 0; j--)
                    {
                        free(pMaze->array[j]);
                    }
                    free(pMaze->array);
                    free(pMaze);
                    pMaze = NULL;
                    return pMaze;
                }
            }

            // INITIALISATION
            unsigned int e = startValue;
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
        else
        {
            free(pMaze);
            pMaze = NULL;
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

bool openDoor(maze* pMaze, segments* pSegments,int index)
{
    bool state = false;
    if(pMaze != NULL && pSegments != NULL && index != -1)
    {
        if(*pSegments->arraySegment[index].b != *pSegments->arraySegment[index].a)
        {
            for(int i = 0; i < pMaze->height; i++)
            {
                for(int j = 0; j < pMaze->width; j++)
                {
                    if(pSegments->arraySegment[index].b != &pMaze->array[i][j])
                    {
                        if(*pSegments->arraySegment[index].b == pMaze->array[i][j])
                        {
                                pMaze->array[i][j] = *pSegments->arraySegment[index].a;
                                state = true;
                        }
                    }
                }
            }

            *pSegments->arraySegment[index].b = *pSegments->arraySegment[index].a;
            pSegments->arraySegment[index].visited = true;
        }
    }
    return state;
}
