#include <stdlib.h>
#include "slist.h"

#undef slistc_cpy

ssize_t slistc_cpy(Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    slistc_free(_dst->next); //del _dst

    _src = _src->next; //skip head node

    size_t i = 0; //count variable

    while (_src) //traverse lst
    {
        _dst->next = slistc_init(); //create a node
        _dst = _dst->next;          //goto node

        _dst->ch = _src->ch; //assign value

        _src = _src->next; //goto node

        i++; //count plus one
    }

    return i; //return count
}