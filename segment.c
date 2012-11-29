#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "segment.h"

/*TODO : TO IMPROVE */
segments* createSegments(maze* pMaze)
{
   unsigned int e = 0;
   segments* pSegments = NULL;
   if(pMaze != NULL)
    {
        pSegments = malloc(sizeof(segments));
        if(pSegments != NULL)
        {
            pSegments->size = (pMaze->height * pMaze->width * 2) - (pMaze->height + pMaze->width);
            pSegments->arraySegment = malloc(sizeof(segment) * pSegments->size);
            if(pSegments != NULL)
            {
                for(int i = 0; i < pMaze->height; i++) // ligne
                {
                    for(int j = 0; j < pMaze->width; j++) // colonne
                    {
                        /*
                           [1][2][3]
                           [4][5][6]
                           [7][8][9]
                        */

                       /* if((j-1) >= 0)
                        {
                            pSegments->arraySegment[e].a = &pMaze->array[i][j];    // [5]
                            pSegments->arraySegment[e].b = &pMaze->array[i][j-1];  // [4]
                            pSegments->arraySegment[e].visited = false;
                            e++;
                        }

                        if((i-1) >= 0)
                        {
                            pSegments->arraySegment[e].a = &pMaze->array[i][j];    // [5]
                            pSegments->arraySegment[e].b = &pMaze->array[i-1][j];  // [2]
                            pSegments->arraySegment[e].visited = false;
                            e++;
                        }
*/
                        if((i+1) < pMaze->height)
                        {
                            pSegments->arraySegment[e].a = &pMaze->array[i][j];    // [5]
                            pSegments->arraySegment[e].b = &pMaze->array[i+1][j];  // [8]
                            pSegments->arraySegment[e].visited = false;
                            e++;
                        }

                        if((j+1) < pMaze->width)
                        {
                            pSegments->arraySegment[e].a = &pMaze->array[i][j];    // [5]
                            pSegments->arraySegment[e].b = &pMaze->array[i][j+1];  // [6]
                            pSegments->arraySegment[e].visited = false;
                            e++;
                        }
                    }
                }
            }
        }
    }
    return pSegments;
}

bool destroySegments(segments* pSegments)
{
    bool state = false;
    if(pSegments != NULL)
    {
        free(pSegments->arraySegment);
        pSegments->arraySegment = NULL;

        /* reinitialiser le pointeur à NULL
           permet d'eviter un crash si l'on renvoi une deuxieme
           fois cette structure en parametre de la fonction
           free().
        */
        free(pSegments);
        pSegments = NULL;

        state = true;
    }

    return state;
}
