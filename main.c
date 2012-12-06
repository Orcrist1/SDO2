/**
 * @file main.c
 * @brief gestion d'un labyrinthe
 * @author Julien RAMAKERS
 * @date 15 Novembre 2012
 *
 * Ce programme permet de créer un labyrinthe ainsi que
 * de l'afficher avec une interface graphique.
 *
 * l'algoritme de création du labyrinthe :
 *  + l'algorithme de Kruskal -> Complexité : N^2
 */

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "myRandom.h"
#include "display.h"

#define N 12 // TAILLE DU LABYRINTHE

int main(void)
{
    int ret = 0;
    maze* pMaze = createMaze(N, N, 0);

    if(pMaze != NULL)
    {
        segments* pSegments = createSegments(pMaze);
        if(pSegments != NULL)
        {
            randomNumber* pRandomNumber =  createNumberRandom(0, pSegments->size);
            if(pRandomNumber != NULL)
            {
                for(unsigned int i = 0; i < pSegments->size; i++)
                    openDoor(pMaze, pSegments, getRandomNumber(pRandomNumber));

                display(pMaze, pSegments);
                if(!destroyNumberRandom(pRandomNumber))
                    ret = EXIT_FAILURE; /*pour prévenir le systeme que la fermeture du logiciel
                                          ne s'est pas bien déroulée*/
            }
             if(!destroySegments(pSegments))
                ret = EXIT_FAILURE;
        }
        if(!destroyMaze(pMaze))
           ret = EXIT_FAILURE;
    }

    return ret;
}
