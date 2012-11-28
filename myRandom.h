#ifndef MYRANDOM_H_INCLUDED
#define MYRANDOM_H_INCLUDED
#include <stdbool.h>
/* ce fichier contient des fonctions qui permets l'exclusion automatique des nombres qui ont déjà
été ressortis par une de ses fonctions*/
typedef struct randomNumber_t
{
    unsigned int* pNumber;
    unsigned int size;
} randomNumber;

randomNumber* createNumberRandom(unsigned int a, unsigned int b);
bool destroyNumberRandom(randomNumber* number);
int getRandomNumber(randomNumber* number);



#endif // MYRANDOM_H_INCLUDED
