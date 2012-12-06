#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "display.h"

void display(maze* pMaze, segments* pSegments)
{
   if(SDL_Init(SDL_INIT_VIDEO) == -1)
   {
        fprintf(stderr, "erreur lors l'initialisation de la bibliotheque SDL : %s\n", SDL_GetError());
        /*
         suite à l'envoi du code -1, le systeme va liberer toute la memoire
         et quitter l'application.
        */
        exit(EXIT_FAILURE);
   }

   SDL_Surface* mainArea = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

   if(mainArea != NULL)
   {
      int intervalX = WIDTH / pMaze->width + THICKNESS_SEGMENT;
      int intervalY = HEIGHT / pMaze->height + THICKNESS_SEGMENT;

      SDL_WM_SetCaption("Julien RAMAKERS - maze", NULL);
      SDL_FillRect(mainArea, NULL, SDL_MapRGB(mainArea->format, 0, 0, 0));
      SDL_Surface *surfaceSegmentV = SDL_CreateRGBSurface(SDL_HWSURFACE, THICKNESS_SEGMENT, intervalY, 32, 0, 0, 0, 0);
      SDL_Surface *surfaceSegmentH = SDL_CreateRGBSurface(SDL_HWSURFACE, intervalX, THICKNESS_SEGMENT, 32, 0, 0, 0, 0);
      SDL_Rect position;

      int x = 1;
      int y = 0;
      for(unsigned int i = 1; i < pSegments->size;)
      {
         if(x >= pMaze->width) // si X est arrivé à la fin de la ligne
         {
            y++;
            x = 1;
            if(pMaze->width != (y + 1)) i += 1; // si il est different à la derniere ligne
         }

         if(!pSegments->arraySegment[i].visited)
         {
            position.x = intervalX * x;
            position.y = intervalY * y;
            SDL_FillRect(surfaceSegmentV, NULL, SDL_MapRGB(mainArea->format,255,0,0));
            SDL_BlitSurface(surfaceSegmentV,  NULL,  mainArea, &position);
         }
         x++;

         if(pMaze->width == (y + 1)) i += 1;   // s'il est égal à la derniere ligne
         else i += 2;
      }

      x = 0;
      y = 0;
      for(unsigned int i = 0; i < pSegments->size; )
      {
         if(x >= pMaze->width) // si X est arrivé à la fin de la ligne
         {
            y++;
            x = 0;
            if(pMaze->width != (y + 1)) i += 1; // s'il est different à la derniere ligne
            else break;
         }

         if(!pSegments->arraySegment[i].visited)
         {
            position.x = intervalX * x;
            position.y = intervalY * (y + 1);
            SDL_FillRect(surfaceSegmentH, NULL, SDL_MapRGB(mainArea->format,255,0,0));
            SDL_BlitSurface(surfaceSegmentH,  NULL,  mainArea, &position);
         }
         x++;

         if(x < pMaze->width) i += 2;
      }

      SDL_Flip(mainArea);
      SDL_FreeSurface(surfaceSegmentH);
      SDL_FreeSurface(surfaceSegmentV);
      SDLPause();
      SDL_Quit(); //libère la variable "mainArea"
   }

}

void SDLPause(void)
{
   int continuer = 1;
   SDL_Event event;

   while(continuer)
   {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
      case SDL_QUIT:
         continuer = 0;
      }
   }
}

