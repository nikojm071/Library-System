#ifndef VECTOR_H
#define VECTOR_H
#include "status.h"
#include "book.h"

typedef void* VECTOR;

VECTOR vector_init_default(void);
void vector_destroy(VECTOR* phVector);

Status vector_push_back(VECTOR hVector, Book pBook);
Status vector_pop(VECTOR hVector);
Book* vector_at(VECTOR hVector, int index);
int vector_size(VECTOR hVector);
Status vector_empty(VECTOR hVector);

#endif