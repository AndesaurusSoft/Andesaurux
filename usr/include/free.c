#include "stdlib.h"
free(int ptr)
{
    Header *bp, *p;

    bp = (Header *)ptr - 1; // Point to block header

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) 
    {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) 
        {
            break; // Freed block at start or end of arena
        }
    }

    if (bp + bp->s.size == p->s.ptr) 
    { // Join to upper neighbor
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } 
    else 
    {
        bp->s.ptr = p->s.ptr;
    }

    if (p + p->s.size == bp) 
    { // Join to lower neighbor
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else 
    {
        p->s.ptr = bp;
    }

    freep = p;
}