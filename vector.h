#ifndef VECTOR_H
#define VECTOR_H
#include "string.h"

typedef void* VECTOR;

enum status {FAILURE, SUCCESS};
typedef enum status Status;

VECTOR init_default(void);
void destroy(VECTOR* phVector);

Status push_back(VECTOR hVector, STRING hString);
Status pop(VECTOR hVector);
STRING* at(VECTOR hVector, int index);
int size(VECTOR hVector);
Status empty(VECTOR hVector);

#endif