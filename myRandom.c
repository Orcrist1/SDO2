#include "myRandom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

randomNumber* createNumberRandom(unsigned int a, unsigned int b)
{
    randomNumber* number = malloc(sizeof(randomNumber));
    srand(time(NULL));
    if(number != NULL)
    {
        number->pNumber = malloc(sizeof(int*) * (b - a));
        if(number->pNumber != NULL)
        {
            for(unsigned int i = a; i < b; i++)
            {
                number->pNumber[i] = i;
            }
            number->size = b - a;
        }
        else
        {
            free(number);
            number = NULL;
        }
    }

    return number;
}

bool destroyNumberRandom(randomNumber* number)
{
    bool state = false;

    if(number != NULL)
    {
        free(number->pNumber);
        free(number);
        number = NULL;

        state = true;
    }

    return state;
}

int getRandomNumber(randomNumber* number)
{
    unsigned int index;
    unsigned int newNumber;
    if(number->size != 0)
    {
        index = (rand() / (double)RAND_MAX) * number->size;
        newNumber = number->pNumber[index];
        number->pNumber[index] = number->pNumber[number->size - 1];
        number->size -=  1;
    }
    else
        return -1;

    return newNumber;
}
