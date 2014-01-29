/*
    DESCRIPTION: Implementation of Dynamic arrays. Based in realloc()
    Author: Zed A. Shaw
    Modded by: Faiz Kothari
    version: 0.1

    TODO:
    1. Implement Mapping
    2. Provide some kind of sorting!
*/

#ifndef _DARRAY_H
#define _DARRAY_H
#include <stdlib.h>
//#include <assert.h>
//#include <lcthw/dbg.h>

typedef struct DArray{
    int end;
    int max;
    size_t element_size;
    size_t expand_rate;
    void **contents;
} DArray;

DArray *DArray_create(size_t element_size, size_t initial_max);

void DArray_destroy(DArray *array);

void DArray_clear(DArray *array);

int DArray_expand(DArray *array);

int DArray_contract(DArray *array);

int DArray_push(DArray *array, void *el);

void *DArray_pop(DArray *array);

void DArray_clear_destroy(DArray *array);

#define DArray_last(A) ((A)->contents[(A)->end - 1])
#define DArray_first(A) ((A)->contents[0])
#define DArray_end(A) ((A)->end)
#define DArray_count(A) DArray_end(A)
#define DArray_max(A) ((A)->max)

#define DEFAULT_EXPAND_RATE 300


static inline void DArray_set(DArray *array, int i, void *el)
{
    //darray attempt to set past max
    if(i < array->max){
        if(i > array->end)
            array->end = i;
        array->contents[i] = el;
    }
    else
        return;
}

static inline void *DArray_get(DArray *array, int i)
{
    //darray attempt to get past max
    if(i < array->max)
        return array->contents[i];
    else
        return NULL;
}

static inline void *DArray_remove(DArray *array, int i)
{
    void *el = array->contents[i];
    array->contents[i] = NULL;
    return el;
}
static inline void *DArray_new(DArray *array)
{
    //Can't use DArray_new on 0 size darrays.
    if(array->element_size > 0)
        return calloc(1, array->element_size);
    else
        return NULL;
}

#define DArray_free(E) free((E))

#endif