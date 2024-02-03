#include "stdlib.h"
#include "time.h"
#include "unistd.h"
free(ptr)
{
    Header *bp, *p;

    bp = (Header *)ptr - 1; /* Point to block header */

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) 
    {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) 
        {
            break;
        }
    }

    if (bp + bp->s.size == p->s.ptr) 
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } 
    else 
    {
        bp->s.ptr = p->s.ptr;
    }

    if (p + p->s.size == bp) 
    {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    }
    else 
    {
        p->s.ptr = bp;
    }
    freep = p;
}

exit(status)
{
    return status;
}

system(cmd)
const char *cmd;
{
    execl("/usr/bin/minian/main.o", "system", cmd, (char *)NULL);
    exit(EXIT_SUCCESS);
}