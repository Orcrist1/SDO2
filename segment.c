#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "segment.h"

static void initSegments(maze* pMaze, segments* pSegments)
{
    /*
        pas besoin de verifier si pMaze est différent de NULL
        ou que pSegment le soit aussi, étant donné qu'ils ont
        ete créé correctement !
    */
   unsigned int e = 0;
   for(int i = 0; i < pMaze->height; i++) // ligne
   {
      for(int j = 0; j < pMaze->width; j++) // colonne
      {
         /*
            [1][2][3]
            [4][5][6]
            [7][8][9]
         */
         /*
         si le segment du bas depasse pas la hauteur maximum
         du labyrinthe alors on initialise le segment.
         */
         if((i+1) < pMaze->height)
         {
            pSegments->arraySegment[e].a = &pMaze->array[i][j];    // [5]
            pSegments->arraySegment[e].b = &pMaze->array[i+1][j];  // [8]
            pSegments->arraySegment[e].visited = false;
            e++;
         }
         /*
         si le segment de droite depasse pas la largeur maximum
         du labyrinthe alors on initialise le segment.
         */
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

segments* createSegments(maze* pMaze)
{
   segments* pSegments = NULL;
   if(pMaze != NULL)
   {
      pSegments = malloc(sizeof(segments));
      if(pSegments != NULL)
      {
         pSegments->size = (pMaze->height * pMaze->width * 2) - (pMaze->height + pMaze->width);
         pSegments->arraySegment = malloc(sizeof(segment) * pSegments->size);

         //INITIALISATION
         if(pSegments->arraySegment != NULL)
         {
            initSegments(pMaze, pSegments);
         }
         else
         {
            free(pSegments->arraySegment);
            free(pSegments);
            pSegments = NULL;
         }
      }
      else
      {
        free(pSegments);
        pSegments = NULL;
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

      /*
         reinitialiser le pointeur à NULL
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
