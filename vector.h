#ifndef VECTOR_H
#define VECTOR_H
#include "string.h"
typedef void* VECTOR;

enum status {FAILURE, SUCCESS};
typedef enum status Status;

enum bool {FALSE, TRUE};
typedef enum bool Bool;

VECTOR init_default(void);
void destroy(VECTOR* phVector);

Status push_back(VECTOR hVector, STRING hString);
Status pop(VECTOR hVector);
int* at(VECTOR hVector, int index);
int size(VECTOR hVector);
void empty(VECTOR hVector);

#endif