#ifndef MYRANDOM_H_INCLUDED
#define MYRANDOM_H_INCLUDED
#include <stdbool.h>

typedef struct randomNumber_t
{
    unsigned int* pNumber;
    unsigned int size;
} randomNumber;

randomNumber* createNumberRandom(unsigned int a, unsigned int b);
bool destroyNumberRandom(randomNumber* number);
int getRandomNumber(randomNumber* number);



#endif // MYRANDOM_H_INCLUDED
