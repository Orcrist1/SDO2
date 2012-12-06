#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED
#include <stdbool.h>

typedef struct segment_t segment;
struct segment_t
{
    unsigned int* a;
    unsigned int* b;
    bool visited;
};

typedef struct segments_t segments;
struct segments_t
{
    unsigned int size;
    segment* arraySegment;
};

segments* createSegments(maze* pMaze);

//static void initSegments(maze* pMaze, segments* pSegments);
//Etant une fonction statique, il ne peut exister de prototype !


bool destroySegments(segments* pSegments);



#endif // SEGMENT_H_INCLUDED
