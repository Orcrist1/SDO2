#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "display.h"

/*
allocSegmentGraphique()
positionementElementsGraphique()

*/

void display(maze* pMaze, segments* pSegments)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface* mainArea = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);

    if(mainArea != NULL)
    {
        int intervalX = WIDTH / pMaze->width;
        int intervalY = HEIGHT / pMaze->width;

        SDL_WM_SetCaption("Julien RAMAKERS - maze", NULL);
        SDL_FillRect(mainArea, NULL, SDL_MapRGB(mainArea->format, 0, 0, 0));
        SDL_Surface *surfaceSegmentV = SDL_CreateRGBSurface(SDL_HWSURFACE, THICKNESS_SEGMENT, intervalY, 32, 0, 0, 0, 0);
        SDL_Surface *surfaceSegmentH = SDL_CreateRGBSurface(SDL_HWSURFACE, intervalX, THICKNESS_SEGMENT, 32, 0, 0, 0, 0);
        SDL_Rect position;

        //SEGMENTS HORIZONTAUX
        int index = 0;
        for(unsigned int j = 0; j < (pSegments->size / 2); j++)
        {
           /* position.x = 0;
            position.y = intervalY * j;
            SDL_FillRect(surfaceSegmentV, NULL, SDL_MapRGB(mainArea->format,255,0,0));
            SDL_BlitSurface(surfaceSegmentV,  NULL,  mainArea,  &position);*/

            for(unsigned int i = 0; i < (pSegments->size / 2); i++)
            {

                /*if((j - 1) >= 0 && !pSegments->arraySegment[index].visited)
                {
                    position.x = intervalX * i - THICKNESS_SEGMENT;
                    position.y = intervalY * j;
                    SDL_FillRect(surfaceSegmentH, NULL, SDL_MapRGB(mainArea->format,255,0,0));
                    SDL_BlitSurface(surfaceSegmentH,  NULL,  mainArea, &position);
                    printf("index : %d\n", index);
                }
                index++;
                if(index >= pSegments->size) break;

                if((i - 1) >= 0 && !pSegments->arraySegment[index].visited)
                {
                    position.x = intervalX * i;
                    position.y = intervalY * j - THICKNESS_SEGMENT;
                    SDL_FillRect(surfaceSegmentV, NULL, SDL_MapRGB(mainArea->format,255,0,0));
                    SDL_BlitSurface(surfaceSegmentV,  NULL,  mainArea, &position);
                    printf("index : %d\n", index);
                }
                index++;
                if(index >= pSegments->size) break;*/

                if((j + 1) < pMaze->width + 2  && !pSegments->arraySegment[index].visited)
                {
                    position.x = intervalX * i;
                    position.y = intervalY * (j + 1);
                    SDL_FillRect(surfaceSegmentH, NULL, SDL_MapRGB(mainArea->format,255,0,0));
                    SDL_BlitSurface(surfaceSegmentH,  NULL,  mainArea, &position);
                    SDL_Flip(mainArea);
                }
                index++;

                if((i + 1) < pMaze->height + 2 && !pSegments->arraySegment[index].visited)
                {
                    position.x = intervalX * (i + 1);
                    position.y =  intervalY * j;
                    SDL_FillRect(surfaceSegmentV, NULL, SDL_MapRGB(mainArea->format,255,0,0));
                    SDL_BlitSurface(surfaceSegmentV,  NULL,  mainArea, &position);
                    SDL_Flip(mainArea);
                }
                index++;
            }

        /*    position.x = intervalX * pMaze->width - THICKNESS_SEGMENT;
            position.y = intervalY * j;
            SDL_FillRect(surfaceSegmentV, NULL, SDL_MapRGB(mainArea->format,255,0,0));
            SDL_BlitSurface(surfaceSegmentV,  NULL,  mainArea, &position);*/
        }

        //SEGMENTS VERTICAUX
        /*
       for(int j = 0; j < pMaze->width; j++)
        {
            position.x = intervalY * j;
            position.y = 0;
            SDL_FillRect(surfaceSegmentH, NULL, SDL_MapRGB(mainArea->format,255,0,0));
            SDL_BlitSurface(surfaceSegmentH,  NULL,  mainArea,  &position);
            for(int i = 0; i < pMaze->width; i++)
            {
                position.x = intervalX * i;
                position.y = intervalY * j - THICKNESS_SEGMENT;
                SDL_FillRect(surfaceSegmentH, NULL, SDL_MapRGB(mainArea->format,255,0,0));
                SDL_BlitSurface(surfaceSegmentH,  NULL,  mainArea, &position);
            }
        }*/

        SDL_Flip(mainArea);
        SDL_FreeSurface(surfaceSegmentH);
        SDL_FreeSurface(surfaceSegmentV);
        SDLPause();
    }
    SDL_Quit();
}


void SDLPause(void)
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
