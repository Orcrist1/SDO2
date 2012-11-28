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
bool initSegment(maze* pMaze, segment* pSegment, int i, int j);
bool destroySegments(segments* pSegments);



#endif // SEGMENT_H_INCLUDED
