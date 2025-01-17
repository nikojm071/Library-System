#ifndef STRING_C
#define STRING_C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

struct string{
    char* data;
    int size;
    int capacity;
};
typedef struct string String;


#endif