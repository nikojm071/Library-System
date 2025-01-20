#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "string.h"
#include "status.h"
#include "book.h"

struct vector{
    Book* data;
    int size;
    int capacity;
};
typedef struct vector Vector;

Status resize(Vector* pVector, int newCapacity);

VECTOR vector_init_default(void)
{
    Vector* pVector = (Vector*)malloc(sizeof(Vector));
    if(!pVector)
    {
        fprintf(stderr, "Failed to allocate memory...\n");
        exit(1);
    }
    pVector->size = 0;
    pVector->capacity = 10;
    pVector->data = (Book*)malloc(pVector->capacity * sizeof(Book));
    if(!pVector->data)
    {
        fprintf(stderr, "Failed to allocate memory...\n");
        exit(1);
    }
    
    return pVector;
}

void vector_destroy(VECTOR* phVector)
{
    Vector* pVector = (Vector*)*phVector;
    free(pVector->data);
    free(pVector);
    pVector = NULL;
}

Status vector_push_back(VECTOR hVector, Book pBook)
{
    Vector* pVector = (Vector*)hVector;
    if(pVector->size >= pVector->capacity)
    {
        if(!resize(pVector, (pVector->capacity *2)))
            return FAILURE;
    }
    pVector->data[pVector->size] = pBook;
    pVector->size++;
    return SUCCESS;
}

Status vector_pop(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    if(pVector->size == 0)
    {
        fprintf(stderr, "Unable to pop. This vector is already empty...\n");
        return FAILURE;
    }
    pVector->size--;

    if(pVector->capacity <= pVector->size/2)
    {
        if(resize(pVector, (pVector->capacity/2)))
            return FAILURE;
    }
    
    return SUCCESS;
}

Book* vector_at(VECTOR hVector, int index)
{
    Vector* pVector = (Vector*)hVector;
    if(index < 0 || index > pVector->size)
    {
        fprintf(stderr, "This index is out of bounds.\n");
        exit(1);
    }
    return &pVector->data[index];
}

int vector_size(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return pVector->size;
}

Status vector_empty(VECTOR hVector)
{
    Vector* pVector = (Vector*)hVector;
    return (!pVector->size);
}

Status resize(Vector* pVector, int newCapacity)
{
    Book* temp = (Book*)malloc(sizeof(Book) * newCapacity);
    if(!temp)
    {
        fprintf(stderr, "Failed to allocate memory upon resize request...\n");
        return FAILURE;
    }
    for(int i = 0; i < pVector->size; i++)
    {
        temp[i] = pVector->data[i];
    }
    free(pVector->data);
    pVector->capacity = newCapacity;
    pVector->data = temp;
    return SUCCESS;
}