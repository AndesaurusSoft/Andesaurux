#include "stdlib.h"
malloc(unsigned nbytes)
{
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;

    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if ((prevp = freep) == NULL) // No free list yet
    {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr)
    {
        if (p->s.size >= nunits) // Big enough
        {
            if (p->s.size == nunits) // Exact size
            {
                prevp->s.ptr = p->s.ptr;
            }
            else // Allocate the end part
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }

        if (p == freep) // Wrapped around the free list
        {
            if ((p = morecore(nunits)) == NULL)
            {
                return NULL; // No memory left
            }
        }
    }
}