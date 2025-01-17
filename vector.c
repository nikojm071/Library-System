#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "string.h"

struct vector{
    STRING* data;
    int size;
    int capacity;
};
typedef struct vector Vector;

Status resize(Vector* pVector, int newCapacity);

VECTOR init_default(void)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(!pVector)
    {
        fprintf(stderr, "Failed to allocate memory...\n");
        exit(1);
    }
    pVector->size = 0;
    pVector->capacity = 10;
    pVector->data = (STRING*)malloc(pVector->capacity * sizeof(STRING));
    if(!pVector->data)
    {
        fprintf(stderr, "Failed to allocate memory...\n");
        exit(1);
    }
    
    return pVector;
}
void destroy(VECTOR* phVector)
{
    Vector* pVector = (Vector*)*phVector;
    //not sure which is correct yet. will test at a later date.
    /*for(int i = 0; i < pVector->size; i++)
        sDestroy(&pVector->data[pVector->size]);
    */
    free(pVector->data);
    free(pVector);
    pVector = NULL;
}

Status push_back(VECTOR hVector, STRING hString)
{
    Vector* pVector = (Vector*)hVector;
    if(pVector->size >= pVector->capacity)
    {
        if(!resize(pVector, pVector->size*2))
            return FAILURE;
    }
    pVector->data[pVector->size] = hString;
    pVector->size++;
    return SUCCESS;
}

Status pop(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    if(pVector->size == 0)
    {
        fprintf(stderr, "Unable to pop. This vector is already empty...\n");
        return FAILURE;
    }
    pVector->size--;
    return SUCCESS;
}

STRING* at(VECTOR hVector, int index)
{
    Vector* pVector = (Vector*)hVector;
    if(index < 0 || index > pVector->size)
    {
        fprintf(stderr, "This index is out of bounds.\n");
        exit(1);
    }
    return &pVector->data[index];
}

int size(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->size;
}

Status empty(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return (!pVector->size);
}

Status resize(Vector* pVector, int newCapacity)
{
    Vector* temp = (Vector*)malloc(sizeof(Vector));
    if(!temp)
    {
        fprintf(stderr, "Failed to allocate memory upon resize request...\n");
        return FAILURE;
    }
    temp->data = (STRING*)malloc(newCapacity * sizeof(STRING));
    if(!temp->data)
    {
        fprintf(stderr, "Failed to allocate memory upon resize request...\n");
        return FAILURE;
    }
    temp->data = pVector->data;
    free(pVector->data);
    free(pVector);
    pVector = temp;
    return SUCCESS;
}